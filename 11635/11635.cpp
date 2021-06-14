#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

const int MAX_CITIES = 10005;
const int MAX_HOTELS = 102;
const int MAX_DIST = 599;
const int INF = 1000000;

class Vertex {
public:
	unordered_set< int > connections;
};

void initAdjCities() {
	for( auto& i : adjCities )
		for( auto& j : i )
			j = INF;
	for( int i = 0; i < MAX_CITIES; i++ )
		adjCities[ i ][ i ] = 0;
}

void initAdjHotels() {
	for( auto& i : adjHotels )
		for( auto& j : i )
			j = 0;
	for( int i = 0; i < MAX_HOTELS; i++ )
		adjHotels[ i ][ i ] = 1;
}

void initAllCities() {
	for( auto& i : allCities )
		i.connections.clear();
}

void SPFA( int source ) {
	queue< int > vertexForRelax;
	vertexForRelax.push( source );

	int distFromSource[ MAX_CITIES ];
	for( int i = 0; i < MAX_CITIES; i++ ) {
		distFromSource[ i ] = INF;
	}
	while( !vertexForRelax.empty() ) {
		relax( vertexForRelax );
	}
	for( int i = 0; i < MAX_HOTELS; i++ ) {
		if( distFromSource[ hotels[ i ] ] < MAX_DIST ) {
			adjHotels[ hotels[ i ] ][ source ] = 1;
			adjHotels[ source ][ hotels[ i ] ] = 1;
		}
	}
}

void relax( queue< int >& vertexForRelax ) {
	int now;
	now = vertexForRelax.front();
	vertexForRelax.pop();
	for( int& n : allCities[ now ].connections ) {
		int newDistance = distFromSource[ now ] + adjCities[ now ][ n ];
		if( newDistance < distFromSource[ n ] ) {
			distFromSource[ n ] = newDistance;
			vertexForRelax.push( n );
		}
	}
}

void setRoad( int pa, int pb, int distance ) {
	allCities[ pa ].connections.insert( pb );
	allCities[ pb ].connections.insert( pa );
	adjCities[ pa ][ pb ] = min( distance, adjCities[ pa ][ pb ] );
	adjCities[ pb ][ pa ] = min( distance, adjCities[ pa ][ pb ] );
}

int BFS() {
	queue< int > waitForSearchHotels;
	waitForSearchHotels.push( 1 );
}

int adjCities[ MAX_CITIES ][ MAX_CITIES ];
int adjHotels[ MAX_HOTELS ][ MAX_HOTELS ];
Vertex allCities[ MAX_CITIES ];
int hotels[ MAX_HOTELS ];

int main() {
	int citiesNum, hotelsNum, roadsNum;
	while( cin >> citiesNum && citiesNum ) {
		initAdjCities();
		initAdjHotels();
		initAllCities();
		cin >> hotelsNum;
		for( int i = 0; i < hotelsNum; i++ )
			cin >> hotels[ i ];
		hotels[ hotelsNum ] = 1;  // add first and destination city as hotels in order to do SPFA
		hotels[ hotelsNum + 1 ] = citiesNum;
		hotelsNum += 2;
		cin >> roadsNum;
		int pa, pb, dist;
		for( int i = 0; i < roadsNum; i++ ) {
			cin >> pa >> pb >> dist;
			setRoad( pa, pb, dist );
		}
		for( int& i : hotels )
			SPFA( i );
		// TODO: BFS or something to get answer
	}
}