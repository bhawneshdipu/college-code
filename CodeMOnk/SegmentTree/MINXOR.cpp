// MINXOR
// XOR Minimization
// Author: Constantine Sokol
// Complexity : O( N * 16 + M * sqrt( N ) * 16 )
// Expected Verdict: AC

#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 250500;
const int block_size = 700;
const int maxbit = 16;

struct node
{
	int num, next[ 2 ];
	node()
	{
		num = 0;
		next[0] = next[1] = -1;
	}
};

struct block
{
	int value, h;
	node trie[ block_size * maxbit + 5 ];
	block()
	{
		value = 0;
		clear();
	}
	void clear()
	{
		for ( int i = 0; i < block_size * maxbit + 5; i++ ) trie[i] = node();
		h = 1;
	}
	void add( int x )
	{
		int v = 0;
		for ( int i = maxbit - 1; i >= 0; i-- )
		{
			int bit = min( ( 1 << i ) & x, 1 ) ;
			if ( trie[v].next[ bit ] == -1 ) trie[v].next[bit] = h++;
			v = trie[v].next[bit];
		}
		trie[v].num++;
	}
	pair< int, int > fun()
	{
		int v = 0;
		int result = 0;
		for ( int i = maxbit - 1; i >= 0; i-- )
		{
			int bit = min( ( 1 << i ) & value, 1 ) ;
			if ( trie[v].next[ bit ] == -1 )
			{
				v = trie[v].next[ bit ^ 1 ];
				result += ( 1 << i );
				continue;
			}
			v = trie[v].next[ bit ];
		}
		return make_pair( result, trie[v].num );
	}
};

int n, m, h = 0, a[ maxn ], left_id[ maxn ], right_id[ maxn ], id[ maxn ];
block b[ maxn / block_size + 5 ];
bool ok[ maxn / block_size + 5 ];

void rebuild( int id )
{
	b[id].clear();
	for ( int i = left_id[ id ]; i <= right_id[ id ]; i++ ) b[id].add( a[i] );
	ok[id] = true;
}

void sqrt_decomposition()
{
	int pos = 1;
	while ( pos < n )
	{
		++h;
		int left = pos;
		int right = min( pos + block_size - 1, n );
		left_id[ h ] = left;
		right_id[ h ] = right;
		for ( int i = left; i <= right; i++ ) id[i] = h;
		rebuild( h );
		pos = right + 1;
	}
}

pair< int, int > operator+( pair< int, int > a, pair< int, int > b )
{
	if ( a.first < b.first ) return a;
	if ( a.first > b.first ) return b;
	return make_pair( a.first, a.second + b.second );
}

pair< int, int > query( int l, int r )
{
	pair< int, int > result( 1 << maxbit, 0 );
	if ( id[l] == id[r] )
	{
		for ( int i = l; i <= r; i++ ) result = result + make_pair( a[i] ^ b[ id[ i ] ].value, 1 );
		return result;
	}
	int block = id[l];
	for ( int i = l; i <= right_id[ block ]; i++ ) result = result + make_pair( a[i] ^ b[ id[ i ] ].value, 1 );
	l = right_id[ block ] + 1;
	block = id[r];
	for ( int i = left_id[ block ]; i <= r; i++ ) result = result + make_pair( a[i] ^ b[ id[ i ] ].value, 1 );
	r = left_id[ block ] - 1;
	for ( int i = id[l]; i <= id[r]; i++ )
	{
		if ( ok[i] == false ) rebuild( i );
		result = result + b[i].fun();
	}
	return result;
}

void modify( int l, int r, int k )
{
	if ( id[l] == id[r] )
	{
		for ( int i = l; i <= r; i++ ) a[i] ^= k;
		rebuild( id[l] );
		return;
	}
	int block = id[l];
	for ( int i = l; i <= right_id[ block ]; i++ ) a[i] ^= k;
	l = right_id[ block ] + 1;
	ok[ block ] = false;
	//rebuild( block );
	block = id[r];
	for ( int i = left_id[ block ]; i <= r; i++ ) a[i] ^= k;
	r = left_id[ block ] - 1;
	ok[ block ] = false;
	//rebuild( block );
	for ( int i = id[l]; i <= id[r]; i++ ) b[i].value ^= k;
}

int main (int argc, const char * argv[])
{
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	sqrt_decomposition();
	for ( int i = 1; i <= m; i++ )
	{
		int _type, l, r;
		scanf("%d%d%d", &_type, &l, &r);
		if ( _type == 1 )
		{
			pair< int, int > result = query( l, r );
			printf("%d %d\n", result.first, result.second);
		}
		if ( _type == 2 )
		{
			int k; scanf("%d", &k);
			modify( l, r, k );
		}
	}
    return 0;
}
