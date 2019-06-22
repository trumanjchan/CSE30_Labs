#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

// Provide the definition for Graph here, along with anything else you need to make it work...
#include <vector>
#include <deque>

struct Edge {
	string label;
	string vertex;
	Edge(string v,string l)     //Edge is created from beginning end 'l' to end 'v'
	{
		this->label = l;
		this->vertex = v;
	}
};

struct Vertex {
	string label;
	std::vector<Edge*> adjList;

	Vertex(string label) {
		this->label = label;
	}
};

struct pairs
{
	string vertex;
	string edge;
	pairs(string vertex, string edge)
	{
		this->vertex = vertex;
		this->edge = edge;
	}
};

struct triple
{
	string parent;
	string vertex;
	string edge;
	triple(string parent, string vertex, string edge)
	{
		this->parent = parent;
		this->vertex = vertex;
		this->edge = edge;
	}
};

struct Graph {
	std::vector<Vertex*> vertices;

	Graph() {

	}

	void vertexInsert(string newVert) {
		Vertex* v = new Vertex(newVert);
		vertices.push_back(v);     //insert new vertex v
	}

	void edgeInsert(string label, string from, string to) {
		int src = 0, dst = 0;
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->label == from)
			{
				src = i;
			}
			if (vertices[i]->label == to)
			{
				dst = i;
			}

		}

		vertices[src]->adjList.push_back(new Edge(to, label));
		vertices[dst]->adjList.push_back(new Edge(from, label));
	}

	void print() {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i] != NULL) {
				std::cout << vertices[i]->label << ": ";
				for (int j = 0; j < vertices[i]->adjList.size(); j++) {
					std::cout << vertices[i]->adjList[j]->label << " ";
				}
				std::cout << std::endl;
			}
		}
	}

	bool contains(std::vector<string> queue, string value) {
		for (int i = 0; i < queue.size(); i++) {
			if (queue[i] == value) {
				return true;
			}
		}
		return false;
	}

	bool chain(string start, string dest) {
		std::deque<string> q;
		q.push_front(start);

		std::vector<string> seen;
		std::vector<triple*> parent;
		std::deque<pairs*> path;
		parent.push_back(new triple(start, " ", "  "));

		while (!q.empty()) {
			// Get the item in the front of the queue
			string curr = q.at(0);
			// and pop it off
			q.pop_front();

			seen.push_back(curr);

			std::cout << "Now visiting " << curr << std::endl;

			// Check if we are at the destination
			if (curr == dest) {
				//                for (int i = 0; i < parent.size(); i++){
				//                    std::cout << i << " - " << parent[i] << std::endl;
				//                }
				string temp = curr;
				int k = 0;
				for (;k<parent.size();k++)
				{
					if (parent[k]->vertex == temp)
						break;
				}
				while (temp != start) {
					path.push_front(new pairs(parent[k]->vertex,parent[k]->edge));
					temp = parent[k]->parent;
				}
				cout << seen[0];

				for (int i = 0; i < path.size(); i++) {
					std::cout << "(" << path[i]->edge << ") " << path[i]->vertex;
				}
				std::cout << std::endl;

				return true;
			}

			// If we get here, it means that curr is not our 

			int n=0;
			for( ; n < vertices.size(); n++)
			{
				if (vertices[n]->label == curr) break;

			}
			// Get the actual vertex indexed by curr
			Vertex* v = vertices[n];
			// And get a list of all its children
			//std::vector<int> children = v->adjList;

			// Now add the children to the queue
			for (int i = 0; i < v->adjList.size(); i++) {
				if (!contains(seen, v->adjList[i]->vertex)) {
					q.push_back(v->adjList[i]->vertex);

					seen.push_back(v->adjList[i]->vertex);
					parent.push_back(new triple(curr,v->adjList[i]->vertex, v->adjList[i]->label));
				}
			}
		}

		return false;
	}

};

int main(int argc, const char * argv[]) {
    
    // The graph that stores the movie database
    Graph imdb;
    
    
    // Each actor is a vertex
    imdb.vertexInsert("Al Pacino");
    imdb.vertexInsert("Robert De Niro");
    imdb.vertexInsert("Marlon Brando");
    imdb.vertexInsert("Mark Hamill");
    imdb.vertexInsert("Harrison Ford");
    imdb.vertexInsert("Sean Connery");
    imdb.vertexInsert("Kevin Costner");
    imdb.vertexInsert("John Cena");
    
    // If two actors have been in a movie together,
    // they are connected by an edge
    // The edge is labelled witht the name of the movie
    
    imdb.edgeInsert("The Godfather", "Al Pacino", "Marlon Brando");
    imdb.edgeInsert("Heat", "Al Pacino", "Robert De Niro");
    imdb.edgeInsert("Star Wars", "Mark Hamill", "Harrison Ford");
    imdb.edgeInsert("Indiana Jones", "Harrison Ford", "Sean Connery");
    imdb.edgeInsert("The Untouchables", "Sean Connery", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Sean Connery");
    
	//imdb.print();
    imdb.chain("Marlon Brando", "Robert De Niro");
    imdb.chain("Sean Connery", "Harrison Ford");
    imdb.chain("Kevin Costner", "Al Pacino");
    imdb.chain("Mark Hamill", "John Cena");

//    Expected output:
//
//    Marlon Brando (The Godfather) Al Pacino (Heat) Robert De Niro
//    Sean Connery (Indiana Jones) Harrison Ford
//    Kevin Costner (The Untouchables) Robert De Niro (Heat) Al Pacino
//    Mark Hamill is not connected to John Cena
    
    return 0;
}
