#include "Graph.h"

Graph::Graph() : price(0.0f) {

}

void Graph::addNode(float x, float y, const std::string& name) {
    Node newNode(x, y, name);
    nodes.push_back(newNode);
}

void Graph::draw(sf::RenderWindow& window) const {
    for (const auto& edge : edges) {
        edge.draw(window);
    }
    for (const auto& node : nodes) {
        window.draw(node.getDrawable());
    }
}

void Graph::addEdge(Node* startNode, Node* endNode) {
    auto it = std::find_if(edges.begin(), edges.end(), [&](const Edge& edge) {
        return edge.getStartNode() == startNode && edge.getEndNode() == endNode;
        });

    if (it == edges.end()) {
        edges.emplace_back(startNode, endNode);
    }
}

float Graph::calculateDistance(Node* node1, Node* node2) const {
    sf::Vector2f diff = node2->getPosition() - node1->getPosition();
    return std::sqrt(diff.x * diff.x + diff.y * diff.y);
}

Node* Graph::findNodeByName(const std::string& name) const {
    for (auto& node : nodes) {
        if (node.getName() == name) {
            return const_cast<Node*>(&node); 
        }
    }
    return nullptr; 
}
float Graph::calculateCost(float distance) {
    return (distance / 100.0f) * 1000.0f;
}

void Graph::Dijkstra(const std::string& startName, const std::string& endName, Car& car) {
    for (auto& edge : edges) {
        edge.setColor(sf::Color::Red); 
    }
    Node* startNode = findNodeByName(startName);
    Node* endNode = findNodeByName(endName);

    if (!startNode || !endNode) {
        std::cout << "Nodo no encontrado." << std::endl;
        return;
    }

    std::unordered_map<Node*, float> distances;
    for (auto& node : nodes) {
        distances[&node] = std::numeric_limits<float>::infinity();
    }
    distances[startNode] = 0;

    std::unordered_map<Node*, Node*> previousNode;

    std::priority_queue<std::pair<float, Node*>, std::vector<std::pair<float, Node*>>, std::greater<>> pq;
    pq.push({ static_cast<float>(0), startNode });

    while (!pq.empty()) {
        Node* currentNode = pq.top().second;
        pq.pop();

        if (currentNode == endNode) {
            break;
        }

        for (auto& edge : edges) {
            Node* neighbor = nullptr;
            if (edge.getStartNode() == currentNode) {
                neighbor = edge.getEndNode();
            }
            else if (edge.getEndNode() == currentNode) {
                neighbor = edge.getStartNode();
            }

            if (neighbor) {
                float newDist = distances[currentNode] + calculateDistance(currentNode, neighbor);

                std::cout << "Evaluando vecino: " << neighbor->getName() << " con distancia: " << newDist << std::endl;

                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({ newDist, neighbor });
                    previousNode[neighbor] = currentNode; 
                }
            }
        }
    }

    std::vector<Node*> path;
    float totalDistance = 0.0f;  
    for (Node* at = endNode; at != nullptr; at = previousNode[at]) {
        path.push_back(at);
        if (previousNode[at] != nullptr) {
            totalDistance += calculateDistance(at, previousNode[at]);  
        }
    }

    if (path.empty() || path.back() != startNode) {
        std::cout << "No hay camino disponible desde " << startName << " hasta " << endName << "." << std::endl;
        return;
    }

    std::reverse(path.begin(), path.end());
    std::vector<sf::Vector2f> carPath;
    for (const auto& node : path) {
        carPath.push_back(node->getPosition());
    }
    car.setPath(carPath);

    std::cout << std::endl;
    std::cout << "\033[38;5;226m";
    std::cout << "Ruta mas corta desde " << startName << " a " << endName << ": ";

    for (const auto& node : path) {
        std::cout << node->getName() << " -> ";
    }

    std::cout << std::endl;
    std::cout << "\033[0m";
    std::cout << "Distancias minimas desde " << startName << ":" << std::endl;
    for (const auto& pair : distances) {
        std::cout << pair.first->getName() << ": " << pair.second << " unidades" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\033[38;5;196m";
    std::cout << "Distancia total recorrida desde " << startName << " hasta " << endName << ": " << totalDistance << " metros." << std::endl;
    std::cout << "\033[0m";

    price = calculateCost(totalDistance);
    std::cout << "Costo total: " << price << " colones." << std::endl;

    for (size_t i = 1; i < path.size(); i++) {
        Node* currentNode = path[i - 1];
        Node* nextNode = path[i];

        for (auto& edge : edges) {
            if ((edge.getStartNode() == currentNode && edge.getEndNode() == nextNode) ||
                (edge.getStartNode() == nextNode && edge.getEndNode() == currentNode)) {
                edge.setColor(sf::Color(0,110,70));
            }
        }
    }
}

void Graph::initializeGraph()
{
    addNode(1382.0f, 580.0f, "McDonalds");
    addNode(1261.0f, 744.0f, "Mercado");
    addNode(1363.0f, 790.0f, "INS");
    addNode(1335.0f, 704.0f, "Parque");
    addNode(1191.0f, 654.0f, "RepuestosJuanca");
    addNode(1211.0f, 423.0f, "LaGuaca");
    addNode(1235.0f, 337.0f, "Escuela");

    addEdge(findNodeByName("INS"), findNodeByName("Parque"));
    addEdge(findNodeByName("Parque"), findNodeByName("McDonalds"));
    addEdge(findNodeByName("McDonalds"), findNodeByName("Escuela"));
    addEdge(findNodeByName("Escuela"), findNodeByName("LaGuaca"));
    addEdge(findNodeByName("LaGuaca"), findNodeByName("RepuestosJuanca"));
    addEdge(findNodeByName("RepuestosJuanca"), findNodeByName("Mercado"));
    addEdge(findNodeByName("Mercado"), findNodeByName("INS"));

    std::cout << "Conexiones en el grafo:" << std::endl;
    for (const auto& edge : edges) {
        std::cout << edge.getStartNode()->getName() << " <-> "
            << edge.getEndNode()->getName() << std::endl;
    }
}

float Graph::getPrice() {
    return price;
}

//Ejemplo
void Graph::BFS() {
    Node* startNode = findNodeByName("McDonalds");
    if (!startNode) {
        std::cout << "Nodo McDonalds no encontrado." << std::endl;
        return;
    }

    std::unordered_map<Node*, bool> visited; 

    std::queue<Node*> q;
    visited[startNode] = true; 
    q.push(startNode);

    std::cout << "Recorrido BFS comenzando desde: " << startNode->getName() << std::endl;

    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();
        std::cout << currentNode->getName() << " "; 

        for (auto& edge : edges) {
            Node* neighbor = nullptr;
            if (edge.getStartNode() == currentNode) {
                neighbor = edge.getEndNode();
            }
            else if (edge.getEndNode() == currentNode) {
                neighbor = edge.getStartNode();
            }

            if (neighbor && !visited[neighbor]) {
                visited[neighbor] = true; 
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}


