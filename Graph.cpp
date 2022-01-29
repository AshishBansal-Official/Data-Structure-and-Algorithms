#include<iostream>
#include<vector>
#include<iterator>
#include<list>

class Edge {
public:
	int DestinationVertextId;
	int weight;
		
	Edge() {}
	
	Edge(int destVID, int w) : DestinationVertextId(destVID), weight(w) {}
	
	void setEdgeValues (int destVID, int w) {
		DestinationVertextId = destVID;
		weight = w;
	}
	
	void setWeight(int w) {
		weight = w;
	}
	
	int getDestinationVertexId() {
		return DestinationVertextId;
	}
	
	int getWeight() {
		return weight;
	}
};

class Vertex {
public:
	int state_id;
	std::string state_name;
	
	std::list<Edge> edgeList;
	
	Vertex() : state_id(0), state_name("") {}
	
	Vertex(int id, std::string sname) : state_id(id), state_name(sname) {}
	
	int getStateId() {
		return state_id;
	}
	
	std::string getStateName() {
		return state_name;
	}
	
	std::list<Edge> getEdgeList() {
		return edgeList;
	}
	
	void setId(int id) {
		state_id = id;
	}
	
	void setStateName(std::string sname){
		state_name = sname;
	}
	
	void printEdgeList() {
		std::cout<<"[";
		for(auto it = edgeList.begin(); it != edgeList.end(); it++) {
			std::cout<<it->getDestinationVertexId()<<"(" <<it->getWeight()<<") --> ";
		}
		std::cout<<"]";
		std::cout<<std::endl;
	}
	
	void updateVertexName(std::string sname) {
    	state_name = sname;
    	std::cout << "Vertex Name Updated Successfully"<<std::endl;
	}
};

class Graph {
public:
	std::vector<Vertex> vertices;
	
	Vertex getVertexById(int vid) {
		Vertex temp;
		for(int i=0; i<vertices.size(); i++) {
			temp = vertices.at(i);
			if(temp.getStateId() == vid) {
				return temp;
			}
		}
		return temp;
	}
	
	void updateVertex(int vid, std::string sname) {
		bool check = checkIfVertexExistById(vid);
		if(check == true) {
			for(int i=0; i<vertices.size(); i++) {
				if(vertices.at(i).getStateId() == vid) {
					vertices.at(i).setStateName(sname);
					std::cout<<"Vertex(State) Updated Successfully"<<std::endl;
					break;
				}
			}
		} else {
			std::cout<<"Invalid Vertex(State) Id entered."<<std::endl;
		}
	}
	
	void addVertex(Vertex newVertex) {
		bool check = checkIfVertexExistById(newVertex.getStateId());
		if(check == true) {
			std::cout<<"Vertex with this ID already exist"<<std::endl;
		}
		else {
			vertices.push_back(newVertex);
			std::cout<<"New Vertex Added Successfully"<<std::endl;
		}
	}
	
	bool checkIfVertexExistById(int vid) {
		for(int i=0; i<vertices.size(); i++) {
			if(vertices.at(i).getStateId() == vid) {
				return true;
			}
		}
		return false;
	}
	
	bool checkIfEdgeExistById(int fromVertex, int toVertex) {
		Vertex v = getVertexById(fromVertex);
		std::list<Edge> e;
		e = v.getEdgeList();
		for(auto it = e.begin(); it != e.end(); it++) {
			if(it->getDestinationVertexId()== toVertex) {
				return true;
				break;
			}
		}
		return false;
	}
	
	void addEdgeById(int fromVertex, int toVertex, int weight) {
		bool check1 = checkIfVertexExistById(fromVertex);
		bool check2 = checkIfVertexExistById(toVertex);
		if((check1 && check2 == true)) {
			bool check3 = checkIfEdgeExistById(fromVertex, toVertex);
			if(check3 == true) {
				std::cout<<"Edge between "<<getVertexById(fromVertex).getStateName() << "(" << fromVertex << ") and " <<getVertexById(toVertex).getStateName() << "(" << toVertex << ") Already Exists" <<std::endl;
			}
			else {
				for(int i=0; i<vertices.size(); i++) {
					if(vertices.at(i).getStateId() == fromVertex) {
						Edge e(toVertex, weight);
						vertices.at(i).edgeList.push_back(e);
					} else if(vertices.at(i).getStateId() == toVertex) {
						Edge e(fromVertex, weight);
						vertices.at(i).edgeList.push_back(e);
					}
				}
				std::cout<<"Edge between " <<fromVertex << " and " <<toVertex<<" added successfully."<<std::endl;
			}
		} else {
			std::cout<<"Invalid Vertex Id entered." <<std::endl;
		}
	}
	
	void deleteVertexById(int vid) {
		bool check = checkIfVertexExistById(vid);
		int vIndex = 0;
		if(check == true) {
			for(int i=0; i<vertices.size(); i++) {
				if(vertices.at(i).getStateId() == vid) {
					vIndex = i;
				}
			}
			for(int i=0; i<vertices.size(); i++) {
				for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
					if(it -> getDestinationVertexId() == vid) {
						vertices.at(i).edgeList.erase(it);
						break;
					}
				}
			}
			vertices.erase(vertices.begin() + vIndex);
			std::cout<<"Vertex Deleted Successfully"<<std::endl;
		}
	}
	
	void updateEdgeById(int fromVertex, int toVertex, int newWeight) {
		bool check = checkIfEdgeExistById(fromVertex, toVertex);
		if(check == true) {
			for(int i=0; i<vertices.size(); i++) {
				if(vertices.at(i).getStateId() == fromVertex) {
					for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
						if(it -> getDestinationVertexId() == toVertex) {
							it-> setWeight(newWeight);
							break;
						}
					}
				}
				else if(vertices.at(i).getStateId() == toVertex) {
					for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
						if(it->getDestinationVertexId() == fromVertex) {
							it->setWeight(newWeight);
							break;
						}
					}
				}
			}
			std::cout<<"Edge Weight Updated Successfully"<<std::endl;
		} 
		else {
			std::cout<<"Edge between " << getVertexById(fromVertex).getStateName() << "(" <<fromVertex <<") and " <<getVertexById(toVertex).getStateName() << "("<<toVertex <<") DOES NOT Exist"<<std::endl;
		}
	}
	
	void deleteEdgeById(int fromVertex, int toVertex) {
		bool check = checkIfEdgeExistById(fromVertex, toVertex);
		if(check==true) {
			for(int i=0; i<vertices.size();i++) {
				if(vertices.at(i).getStateId() == fromVertex) {
					for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
						if(it -> getDestinationVertexId() == toVertex) {
							vertices.at(i).edgeList.erase(it);
							break;
						}
					}
				} else if(vertices.at(i).getStateId() == toVertex) {
					for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
						if(it -> getDestinationVertexId() == fromVertex) {
							vertices.at(i).edgeList.erase(it);
							break;
						}
					}
				}
			}
			std::cout<<"Edge Between " <<getVertexById(fromVertex).getStateName() << "(" <<fromVertex <<") and " <<getVertexById(toVertex).getStateName() << "("<<toVertex <<") Deleted successfully."<<std::endl;
		}
	}
	
	void getAllNeighborsById(int vid) {
		std::cout<<getVertexById(vid).getStateName() << " (" << getVertexById(vid).getStateId() << ") --> ";
		for(int i=0; i<vertices.size(); i++) {
			if(vertices.at(i).getStateId() == vid) {
				std::cout<<"[";
				for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
					std::cout<<it->getDestinationVertexId() <<"(" <<it->getWeight()<<") --> ";
				}
				std::cout<<"]";
			}
		}
	}
	
	void printGraph() {
		for(int i=0; i<vertices.size(); i++) {
			Vertex temp;
			temp = vertices.at(i);
			std::cout<<temp.getStateName()<<" ("<<temp.getStateId()<<") --> ";
			temp.printEdgeList(); 
		}
	}
};

int main() {
	int option, id1, id2, w;
	Graph g;
	std::string sname;
	Vertex v1;
	bool check = false;
	
	do {
		std::cout<<"What operation do you want to perform?"<<std::endl;
		std::cout<<"Select Option number. Enter 0 to exit."<<std::endl;
		std::cout<<"1. Add Vertex"<<std::endl;
		std::cout<<"2. Update Vertex"<<std::endl;
		std::cout<<"3. Delete Vertex"<<std::endl;
		std::cout<<"4. Add Edge"<<std::endl;
		std::cout<<"5. Update Edge"<<std::endl;
		std::cout<<"6. Delete Edge"<<std::endl;
		std::cout<<"7. Check if 2 Vertices are Neighbors"<<std::endl;
		std::cout<<"8. Print All Neighbors of a Vertex"<<std::endl;
		std::cout<<"9. Print Graph"<<std::endl;
		std::cout<<"10. Clear Screen"<<std::endl;
		std::cout<<"0. Exit Program"<<std::endl;
		
		std::cin>>option;
		
		switch(option) {
			case 0:
				break;
			case 1:
				std::cout<<"Add Vertex Operation - "<<std::endl;
				std::cout<<"Enter State ID : ";
				std::cin>>id1;
				std::cout<<"Enter State Name : ";
				std::cin>>sname;
				v1.setId(id1);
				v1.setStateName(sname);
				g.addVertex(v1);
				break;
			case 2:
				std::cout<<"Update Vertex Operation - "<<std::endl;
				std::cout<<"Enter State Id of Vertex(State) to Update: ";
				std::cin>>id1;
				std::cout<<"Enter State Name: ";
				std::cin>>sname;
				g.updateVertex(id1, sname);
				break;
			case 3:
				std::cout<<"Delete Vertex Operation - "<<std::endl;
				std::cout<<"Enter ID of Vertex(State) to delete: ";
				std::cin>>id1;
				g.deleteVertexById(id1);
				break;
			case 4:
				std::cout<<"Add Edge Operation - "<<std::endl;
				std::cout<<"Enter ID of source Vertex(State) : ";
				std::cin>>id1;
				std::cout<<"Enter ID of Destination Vertex(State) : ";
				std::cin>>id2;
				std::cout<<"Enter Weight of Edge: ";
				std::cin>>w;
				g.addEdgeById(id1, id2, w);
				break;
			case 5:
				std::cout<<"Update Edge Operation - "<<std::endl;
				std::cout<<"Enter ID of Source Vertex(State): ";
				std::cin>>id1;
				std::cout<<"Enter ID of Destination Vertex(State): ";
				std::cin>>id2;
				std::cout<<"Enter UPDATED Weight of Edge: ";
				std::cin>>w;
				g.updateEdgeById(id1, id2, w);
				break;
			case 6:
				std::cout<<"Delete Edge Operation - "<<std::endl;
				std::cout<<"Enter ID of source Vertex(State) : ";
				std::cin>>id1;
				std::cout<<"Enter ID of Destination Vertex(State) : ";
				std::cin>>id2;
				g.deleteEdgeById(id1, id2);
				break;
			case 7:
				std::cout<<"Check if 2 Vertices are Neighbors - "<<std::endl;
				std::cout<<"Enter ID of Source Vertex(State): ";
				std::cin>>id1;
				std::cout<<"Enter ID of Destination Vertex(State): ";
				std::cin>>id2;
				check = g.checkIfEdgeExistById(id1, id2);
				if(check == true) {
					std::cout<<"Vertices are Neighbors (Edge exist)";
				} else {
					std::cout<<"Vertices are NOT Neighbors (Edge does NOT exist)";
				}
				break;
			case 8:
				std::cout<<"Print All Neighbors of a Vertex - "<<std::endl;
				std::cout<<"Enter ID of Vertex(State) to fetch all Neighbors: ";
				std::cin>>id1;
				g.getAllNeighborsById(id1);
				break;
			case 9:
				std::cout<<"Print Graph Operation - "<<std::endl;
				g.printGraph();
				break;
			default:
				std::cout<<"Enter Proper Operation number"<<std::endl;
		}
		std::cout<<std::endl;
	} while(option!=0);
	return 0;
}
