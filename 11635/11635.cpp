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

void initAdjCities();
void initAdjHotels();
void initAllCities();
void SPFA( int hotelIndex );
void relax( queue< int >& vertexForRelax, int* distFromSource );
void setRoad( int pa, int pb, int distance );
int BFS();

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
		for( int i = 0; i < hotels.size(); i++ )
			SPFA( i );
		// TODO: BFS or something to get answer
	}
}

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

void SPFA( int hotelIndex ) {
	queue< int > vertexForRelax;
	vertexForRelax.push( hotels[ hotelIndex ] );

	int distFromSource[ MAX_CITIES ];
	for( int i = 0; i < MAX_CITIES; i++ ) {	 // initialize
		distFromSource[ i ] = INF;
	}
	distFromSource[ hotels[ hotelIndex ] ] = 0;

	while( !vertexForRelax.empty() ) {
		relax( vertexForRelax, distFromSource );
	}
	for( int i = 0; i < MAX_HOTELS; i++ ) {
		if( distFromSource[ hotels[ i ] ] < MAX_DIST ) {
			adjHotels[ hotels[ i ] ][ hotelIndex ] = 1;
			adjHotels[ hotelIndex ][ hotels[ i ] ] = 1;
		}
	}
}

void relax( queue< int >& vertexForRelax, int* distFromSource ) {
	int now;
	now = vertexForRelax.front();
	vertexForRelax.pop();
	for( const int& n : allCities[ now ].connections ) {
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
	adjCities[ pa ][ pb ] = distance;
	adjCities[ pb ][ pa ] = distance;
}

int BFS() {
	queue< int > waitForSearchHotels;
	waitForSearchHotels.push( 1 );
	while( !waitForSearchHotels.empty() ) {
		for( auto i : hotels[] )
	}
}
