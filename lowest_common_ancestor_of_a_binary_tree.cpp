struct MatchNodePredicate

{

    MatchNodePredicate( TreeNode* node_ )

        : node( node_ )

    {

    }



    bool operator()(const vector<TreeNode*>::value_type &node_)

    {

        return node == node_;

    }



    private:

         TreeNode*   node;

};



class Solution {

    vector<TreeNode*> nodeArray_p;

    vector<TreeNode*> nodeArray_q;

    bool findNodeOfTree(TreeNode* root, TreeNode* node, vector<TreeNode*>& nodeArray)

    {

        if(root == node){

            nodeArray.push_back(root);

            return true;

        }

        if(root->left && findNodeOfTree(root->left,node,nodeArray)){

            nodeArray.push_back(root);

            return true;

        }

        if(root->right && findNodeOfTree(root->right,node,nodeArray)){

            nodeArray.push_back(root);

            return true;

        }



        return false;



    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || !p || !q){

            return NULL;

        }

        bool isFind_p = findNodeOfTree(root,p,nodeArray_p);

        bool isFind_q = findNodeOfTree(root,q,nodeArray_q);

        if(!isFind_p || !isFind_q){

            return NULL;

        }



        for(vector<TreeNode*>::const_iterator iter = nodeArray_p.begin();iter != nodeArray_p.end();iter++){

            if(nodeArray_q.end() != find_if(nodeArray_q.begin(),nodeArray_q.end(),MatchNodePredicate(*iter))){

                return *iter;

            }

        }

        return NULL;

    }

};
