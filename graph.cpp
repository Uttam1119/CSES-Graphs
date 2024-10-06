/*
topological sort: any linear ordering of a direct acyclic graph such that if there is any ordering from u to v. then u should come before v.
it is only possible in directed graph which does not have cycle.
bcoz if the graph have cycle.. then it will not be posssible to place the first and last vertex of the graph in the linear ordering.

logic(DFS): maintain a visited array and a stack & adjacency list. call the dfs for every unvisited vertex.
       and after the dfs for any particular vertx is complete.. then push that vertex into the stack.
       and after the dfs for every vertex is complete.
       just simply keep on popping the element from the stack and push that into the res vector.
logic(BFS --> Kahn's Algo): maintain a vector for indegree of vertices and also maintain a queue.
            initially, if any vertex have indegreee as zero, push them all into the queue (in any order coz they dont have any vertices before it so, they will come first in topo)
            then while the queue is not empty, take the front of the queue and push it in the ans vector and decrease the indegree of any vertex connected to this particular element.
            if the indegree of any vertex becomes zero, push it in the queue and do the same.
            int indegree[v] = {0};
            for(int i = 0; i<v; i++){
                for(auto it : adj[v]){
                    indegree[it]+++;
                }
            }
            for(int i = 0; i < indegree.size(); i++){
                if(indegree[i] == 0) q.push(i);
            }
            while(!q.empty()){
                int f = q.front();
                q.pop();
                ans.push_back(f);
                for(auto it : adj[f]){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
                    }
                }
            }
            return ans;

Cyclce detection using BFS: apply kahn's algo in the given graph. after completion of kahn's algo. check if(topo.size() == v) return NO; else return YES;
bcoz if there were any cycle in the graph, then kahn's algorithm will not be able to find the topo sort. and if it is able to find.. means there is no cycle.

Courses 1 (preequisite task): given some pair of task such that if there is a pair of (u,v) then u task should be completed before v in order to complete the task v.
so it is something like topo sort in which it is rule that if there is edge between u and v.. then u should come before v in the linear ordering
so, given the pair of courses.. we will try to form the topo sort, if it is possible then yes.. the courses are possible otherwise not. (means basically it cant have cyclic dependency)

Eventual safe states: a terminal node is that node which does not have any outgoing edges. and a safe node is that node which every path(if possible) leads to a terminal node.
so we have to find the safe nodes.
if we carefully observe the graph, we will see that if any node has outdgree as zero, then it will have indegree as zero (if the edges are reversed)
so, we will initially reverse ever edges and then do the topo sort by BFS(kahn's algo).. and the queue which we will get will be the safe nodes.
the nodes which will not be in the queue will have indegree from node which does not have any path with any terminal node.
(dry run it once).

Alien dictionary: we will be given some word of an alien dictionary and integer N and we have to find the first N letters according to alien dictionary.
means here basically, we r given some words and we have to decide that if a particular letter will come before of another letter.
so, when there is something like in which we have to find the ordering that something comes before something, then topological sorting can be used.
and we r required to print the first N letters (always possible)
so.. we will first traverse in the alien dictionary till N-1 words.. and for every s1 = alien[i] and s2 = alien[i+1] word.. we will compare every letter of both word (upto the length of word which have smallest length in these two)
if any letter is different at the ith index of both the word, then we will add it into the adjacency list by adj[s1[i]].push_back(s2[i])
and after making of adjacency list. simply do the topo sort (kahn's also) and return the topo.
if in the question, given(if possible, only then print) --> then we will search for that case in which a larger length word is given before the smaller length word and all the letter of smaller word matches with the larger word
if this case exists, then it will not be possible to make this alien dictionary. and if there is cyclic dependency, then also we can't have an alien dictionary for the same.

Shortest path in directed acyclic graph(with edges): we will do the topo sort(DFS) and then, relax the edges.
relax the edges means
(i) create a distance array with length equal to N and every value as INT_MAX
(ii) mark the distance[source] = 0
(iii) while(!st.empty()){
    int node = st.top();
    st.pop();
    for(auto it : adj[node]){
        if(dis[node] + it.weight < dis[it]){
            dis[it] = dis[node] + it.weight;
        }
    }
}
we applied topo sort here coz in topo sort we have the first element as the one which does not have any node before that.
and for any node, we r sure that all the previous node before that are added in the stack or we can say the calculation part for sll that node is done.
so, basically in topo sort, we move according to reachability and this reducing the overall steps in covering every node (reduced by O(N+M)).

shortest path in undirected acyclic graph(unit weights): we will maintain a queue and a distance array of N size and all elements equal to INT_MAX
firstly we will add 0 in the queue as the source node 0 will have a distance of zero
then we will do the BFS on graph by
while(!q.empty()){
    int node = q.front().first;
    q.pop();

    for(auto it : adj(node)){
        if(dis[node] + 1 < dis[it]){
            dis[it] = dis[node] + 1;
            q.push(it);
        }
    }
}


*/

