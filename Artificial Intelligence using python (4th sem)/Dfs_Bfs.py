#grah in form of dictionary where values is the child nodes of respective node
graph= {
    'A':["B", "C"],
    'B':["D", "E"],
    'C':["F", "G"],
    'D':["H", "K"],
    'E':["J"],
    'F':[],
    'G':[],
    'H':[],
    'I':[],
    'J':[],
    'K':[]
}

#function to print the value in formatted way
def print_table_row(step, node, fringe, visited):
    print(f"{step:<5} | {node:<10} | {str(fringe):<25} | {str(visited)}")


def dfs(graph, start, goal):
    visited= []
    stack= [start]
    step= 0


    #print table header
    print("\n DFS tracking in table")
    print("step   |     current     |   Fringe(stack)     | visited")
    print("-----------------------------------------------------------------")


    #dfs traversal
    while stack:
        node= stack.pop()
        step+=1


        if node not in visited:
            visited.append(node)

            #display the current search space
            print_table_row(step, node, stack[::-1], visited)

            if node== goal:
                print(f"\n Goal found at {goal} with {step} steps")
                break

            #backtracking from left to right

            for child in reversed(graph[node]):
                if child not in visited:
                    stack.append(child)


#bfs

def bfs(graph, start, goal):
    visited= []
    queue= [start]
    step= 0

     #print table header
    print("\n DFS tracking in table")
    print("step   |     current     |   Fringe(stack)     | visited")
    print("-----------------------------------------------------------------")


    #bfs traversal
    while queue:
        node= queue.pop(0) #take from front node
        step+=1

        if node not in visited:
            visited.append(node)

            #display the current state
            print_table_row(step, node, queue, visited)


        if node== goal:
            print(f"\n goal found at {goal} with {step} steps")
            break


         #enqueue all childrens not visited

        for child in graph[node]:
            if child not in visited and child not in queue:
                queue.append(child)





#set the start node and goal node
start_node= "A"
goal_node= "K"
dfs(graph, start_node, goal_node)
bfs(graph, start_node, goal_node)




