import networkx as nx
import matplotlib.pyplot as plt
  
class GraphVisualization:

    def __init__(self):
        self.visual = []
             
    def visualize(self):
        G = nx.DiGraph()
        G.add_edges_from(self.visual)
        nx.draw_networkx(G)
        plt.show()

    def addEdgesFromFile(self):
        f = open("nodes.txt", 'r')
        for line in f:
            e1 = line.split()[0]
            e2 = line.split()[1]
            self.visual.append([e2, e1])


# Driver code
G = GraphVisualization()
G.addEdgesFromFile()
G.visualize()
