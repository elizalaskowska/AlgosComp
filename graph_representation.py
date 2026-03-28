import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_edgelist("graph.txt", nodetype = int, data = (("weight", int),))
MST = nx.read_edgelist ("mst.txt", nodetype=int, data = (("weight", int),))
edges = MST.edges()
pos=nx.shell_layout(G)
labels=nx.get_edge_attributes(G, 'weight')
labels2=nx.get_edge_attributes(MST, 'weight')
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=500)
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
nx.draw_networkx_edges(G, pos, edges, edge_color = 'red')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels2, font_color='red')
plt.show()