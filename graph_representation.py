import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_edgelist("graph.txt", nodetype = int, data = (("weight", int),))
MST = nx.read_edgelist ("mst.txt", nodetype=int, data = (("weight", int),))

pos=nx.shell_layout(G)
labels=nx.get_edge_attributes(G, 'weight')
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=500, font_weight='bold')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.show()