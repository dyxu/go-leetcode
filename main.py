class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        source, target = 0, len(graph) - 1
        stack = [(source, [source])]
        res, path = [], [source]
        while stack:
            node, path = stack.pop()
            if node == target:
                res.append(path)
            for nbr in graph[node]:
                stack.append((nbr, path + [nbr]))

        return res
