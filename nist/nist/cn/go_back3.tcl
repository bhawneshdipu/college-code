set ns [new Simulator]
set nf [open 661_go_back.nam w]
$ns namtrace-all $nf
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam 661_go_back.nam & 
        exit 0
}

set n0 [$ns node]
$n0 label "sender"
set n1 [$ns node]
$n1 label "receiver"
set n2 [$ns node]
$n2 label "receiver"
set n3 [$ns node]
$n3 label "receiver"


$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n3 2Mb 10ms DropTail


set udp [new Agent/UDP]
$udp set class_ 2
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null
set cbr [new Application/Traffic/CBR]
$cbr set packetsize 500
$cbr set interval_ 0.01
$cbr set random_ 1
$cbr attach-agent $udp

set udp1 [new Agent/UDP]
$udp1 set class_ 2
$ns attach-agent $n0 $udp1
set null1 [new Agent/Null]
$ns attach-agent $n2 $null1
$ns connect $udp1 $null1
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetsize 500
$cbr1 set interval_ 0.01
$cbr1 set random_ 1
$cbr1 attach-agent $udp1



set udpn [new Agent/UDP]
$udpn set class_ 2
$ns attach-agent $n3 $udpn
set nulln [new Agent/Null]
$ns attach-agent $n0 $nulln
$ns connect $udpn $nulln
set cbrn [new Application/Traffic/CBR]
$cbrn set packetsize 5000
$cbrn set interval_ 0.01
$cbrn set random_ 1
$cbrn attach-agent $udpn




set udp2 [new Agent/UDP]
$udp2 set class_ 2
$ns attach-agent $n0 $udp2
set null2 [new Agent/Null]
$ns attach-agent $n2 $null2
$ns connect $udp2 $null2
set cbr2 [new Application/Traffic/CBR]
$cbr2 set packetsize 500
$cbr2 set interval_ 0.01
$cbr2 set random_ 1
$cbr2 attach-agent $udp2


set udp3 [new Agent/UDP]
$udp3 set class_ 2
$ns attach-agent $n0 $udp3
set null3 [new Agent/Null]
$ns attach-agent $n3 $null3
$ns connect $udp3 $null3
set cbr3 [new Application/Traffic/CBR]
$cbr3 set packetsize 500
$cbr3 set interval_ 0.01
$cbr3 set random_ 1
$cbr3 attach-agent $udp3


set udp4 [new Agent/UDP]
$udp4 set class_ 2
$ns attach-agent $n0 $udp4
set null4 [new Agent/Null]
$ns attach-agent $n3 $null4
$ns connect $udp4 $null4
set cbr4 [new Application/Traffic/CBR]
$cbr4 set packetsize 500
$cbr4 set interval_ 0.01
$cbr4 set random_ 1
$cbr4 attach-agent $udp4



set udp5 [new Agent/UDP]
$udp5 set class_ 2
$ns attach-agent $n3 $udp5
set null5 [new Agent/Null]
$ns attach-agent $n0 $null5
$ns connect $udp5 $null5
set cbr5 [new Application/Traffic/CBR]
$cbr5 set packetsize 500
$cbr5 set interval_ 0.01
$cbr5 set random_ 1
$cbr5 attach-agent $udp5


$ns at 0.0 "$cbr start"
$ns at 0.3 "$cbr stop"
$ns at 0.0 "$ns trace-annotate \"frame0 start \""

$ns at 0.4 "$cbr1 start"
$ns at 0.6 "$cbr1 stop"
$ns at 0.4 "$ns trace-annotate \"frame1 start \""

$ns at 0.7 "$cbr4 start"
$ns at 0.9 "$cbr4 stop"
$ns at 0.7 "$ns trace-annotate \"frame 3 start\""


$ns at 1.0 "$cbrn start"
$ns at 1.2 "$cbrn stop"
$ns at 1.0 "$ns trace-annotate \"n ack1  lost start\""


$ns at 1.3 "$cbr2 start"
$ns at 1.5 "$cbr2 stop"
$ns at 1.3 "$ns trace-annotate \"frame2 start\""



$ns at 1.6 "$cbr3 start"
$ns at 1.8 "$cbr3 stop"
$ns at 1.6 "$ns trace-annotate \"frame3 start\""

$ns at 1.8 "$cbr4 start"
$ns at 1.9 "$cbr4 stop"
$ns at 1.9 "$ns trace-annotate \"frame 3 start\""

$ns at 1.9 "$cbr5 start"
$ns at 2.2 "$cbr5 stop"
$ns at 1.9 "$ns trace-annotate \"receive send ACK3\""


$ns at 8.0 "finish"

$ns run






