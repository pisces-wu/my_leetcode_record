
class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

class Solution_106:
    def build_tree(self,inorder,postorder):
        def create_tree(l,r):
            if l>r:
                return None
            val=postorder.pop()
            root=TreeNode(val)
            index=index_map[val]
            root.right=create_tree(index+1,r)
            root.left=create_tree(l,index-1)
            return root
        index_map={val:index for index,val in enumerate(inorder)}
        return create_tree(0,len(postorder)-1)
    def show_tree_preorder(self,root):
        if(root==None):
            return
        print(root.val,"  ")
        self.show_tree_preorder(root.left)
        self.show_tree_preorder(root.right)
if __name__ == '__main__':
    inorder=[9,3,15,20,7]
    postorder=[9,15,7,20,3]
    s_106=Solution_106()
    root=s_106.build_tree(inorder,postorder)
    s_106.show_tree_preorder(root)