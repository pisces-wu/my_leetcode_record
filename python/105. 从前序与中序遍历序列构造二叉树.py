class TreeNode:
    def __init__(self,_val,left=None,right=None):
        self.val=_val
        self.left=left
        self.right=right
class Solution_105:
    def build_tree(self,preorder,inorder):
        def create_tree(l,r):
            if l>r:
                return None
            _val=preorder[0]
            del preorder[0]
            # preorder=preorder[i]
            index=index_map[_val]
            root=TreeNode(_val)
            root.left=create_tree(l,index-1)
            root.right=create_tree(index+1,r)
            return root
        index_map={val:index for index,val in enumerate(inorder)}
        return create_tree(0,len(preorder)-1)
    def show_tree_preorder(self,root):
        if(not root):
            return None
        print(root.val,"  ")
        self.show_tree_preorder(root.left)
        self.show_tree_preorder(root.right)
if __name__ == '__main__':
    preorder=[3,9,20,15,7]
    inorder=[9,3,15,20,7]
    s_105=Solution_105()
    root=s_105.build_tree(preorder,inorder)
    s_105.show_tree_preorder(root)

