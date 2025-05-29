import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import numpy as np

# 假设我们有一些用户数据（例如：年龄、使用频率、互动行为等）
# 这里使用随机生成的数据作为示例
np.random.seed(42)
data = np.random.rand(100, 3)  # 100个用户，3个特征

# 计算不同K值下的SSE
K_values = range(1, 11)  # 测试K值从1到10
SSE = []  # 用于存储每个K值对应的SSE

for K in K_values:
    kmeans = KMeans(n_clusters=K, random_state=42)
    kmeans.fit(data)
    SSE.append(kmeans.inertia_)  # inertia_属性即为SSE

# 绘制手肘法图表
plt.figure(figsize=(8, 6))
plt.plot(K_values, SSE, marker='o', linestyle='-', color='b')
plt.title('Elbow Method for Determining Optimal K')
plt.xlabel('Number of Clusters (K)')
plt.ylabel('Sum of Squared Errors (SSE)')
plt.grid(True)

# 标注拐点（假设拐点在K=3）
plt.annotate('Elbow Point', xy=(3, SSE[2]), xytext=(4, SSE[2] + 0.1),
             arrowprops=dict(facecolor='red', shrink=0.05))

plt.show()