# Creating binary tree
# from given list
from binarytree import build


# List of nodes
nodes =[3, 6, 8, 2, 11, None, 13]

# Building the binary tree
binary_tree = build(nodes)
print('Binary tree from list :\n',
	binary_tree)

# Getting list of nodes from
# binarytree
print('\nList from binary tree :',
	binary_tree.values)
