import matplotlib.pyplot as plt
import numpy as np

labels = []
prim_times= []
kruskal_times = []
boruvka_times = []

with open("results.txt", 'r') as f:
    lines = [line.strip() for line in f if line.strip()]
    for i in range(0, len(lines), 2):
        header = lines[i].split()
        vertices = header[0]
        edges = header[1]
        labels.append(f"vertices:{vertices}\nedges:{edges}")
        times = lines[i+1].split()
        prim_times.append(float(times[0]))
        kruskal_times.append(float(times[1]))
        boruvka_times.append(float(times[2]))

algos = {
    'Prim': prim_times,
    'Kruskal': kruskal_times,
    'Boruvka': boruvka_times,
}

x = np.arange(len(labels))
width = 0.25
multiplier = 0

fig, ax = plt.subplots(layout='constrained', figsize=(12, 7))

for attribute, measurement in algos.items():
    offset = width * multiplier
    rects = ax.bar(x+offset, measurement, width, label=attribute)
    ax.bar_label(rects, padding=3, rotation=45)
    multiplier += 1

ax.set_ylabel('average running time (microsec)')
ax.set_title('MST algorithms comparison')
ax.set_xticks(x+width, labels)
ax.legend(loc='upper left', ncols=3)

if any(algos.values()):
    max_val = max(max(prim_times), max(kruskal_times), max(boruvka_times))
    ax.set_ylim(0, max_val*1.3)

plt.show()
