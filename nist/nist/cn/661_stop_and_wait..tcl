set ns [new Simulator]      
set nf [ open 661_stop_and_wait.nam w ] 
$ns namtrace-all $nf
set nt [ open 661_stop_and_wait.tr w ]
$ns trace-all $nt

set n0  [$ns node]            
$n0 label "Sender"
set n1  [$ns node]
$n1 label "Receiver"




$ns duplex-link $n0 $n1 1Mb 10ms DropTail   

set udp0 [ new Agent/UDP]
set udp1 [ new Agent/UDP]

$ns attach-agent $n0 $udp0         


set n2  [$ns node]            
$n2 label "Sender2"
set n3  [$ns node]
$n3 label "Receiver2"

$ns duplex-link $n2 $n3 1Mb 10ms DropTail   

set udp2 [ new Agent/UDP]
set udp3 [ new Agent/UDP]

$ns attach-agent $n2 $udp2



set cbr0 [new Application/Traffic/CBR]      
$cbr0 set packetsize 500
$cbr0 set interval_ 0.01
$cbr0 set random_ 1
$cbr0 attach-agent $udp0

$ns attach-agent $n1 $udp1

set cbr1 [new Application/Traffic/CBR]      
$cbr1 set packetsize 500
$cbr1 set interval_ 0.01
$cbr1 set random_ 1
$cbr1 attach-agent $udp1

set null0 [ new Agent/Null ]    
$ns attach-agent $n1 $null0
$ns connect $udp0 $null0

set null1 [ new Agent/Null ]    
$ns attach-agent $n0 $null1
$ns connect $udp1 $null1



set cbr2 [new Application/Traffic/CBR]      
$cbr2 set packetsize 500
$cbr2 set interval_ 0.01
$cbr2 set random_ 1
$cbr2 attach-agent $udp2

$ns attach-agent $n3 $udp3

set cbr3 [new Application/Traffic/CBR]      
$cbr3 set packetsize 500
$cbr3 set interval_ 0.01
$cbr3 set random_ 1
$cbr3 attach-agent $udp3

set null2 [ new Agent/Null ]    
$ns attach-agent $n3 $null2
$ns connect $udp2 $null2

set null3 [ new Agent/Null ]    
$ns attach-agent $n2 $null3
$ns connect $udp3 $null3



proc finish {} {          
global ns nf nt
$ns flush-trace
close $nf
close $nt
exec nam 665_stop_and_wait.nam &
exit 0
}

$ns at 0.5 "$cbr0 start" 
$ns at 0.5 "$ns trace-annotate \"sender send frame 0\" "   
$ns at 1.5 "$cbr0 stop"


$ns at 2.5 "$cbr1 start" 
$ns at 2.5 "$ns trace-annotate \"reciver send ack1\" "   
$ns at 3.5 "$cbr1 stop"




$ns at 3.5 "$cbr2 start" 
$ns at 3.5 "$ns trace-annotate \"sender send  frame 1\" "   
$ns at 4.5 "$cbr2 stop"


$ns at 4.5 "$cbr3 start" 
$ns at 4.5 "$ns trace-annotate \"reciver send ack0\" "   
$ns at 6.5 "$cbr3 stop"


$ns at 7.0 " finish "
$ns run                     
