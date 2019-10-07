/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        vector<int> tree1;
        vector<int> tree2;
        
        stack<TreeNode*> nodes;
        
        while(!nodes.empty() || root1 != NULL){
            
            while(root1 != NULL){
                nodes.push(root1);
                root1 = root1->left;
            }
            root1 = nodes.top(); nodes.pop();
            tree1.push_back(root1->val);
            root1 = root1->right;
        }
        
        while(!nodes.empty() or root2 != NULL){
            
            while(root2 != NULL){
                nodes.push(root2);
                root2 = root2->left;
            }
            root2 = nodes.top(); nodes.pop();
            tree2.push_back(root2->val);
            root2 = root2->right;
        }
        
        int i =  0;
        int j = tree2.size() - 1;
        
        while((i < tree1.size() and i >= 0) and j >= 0){ // The condition is crucial
            
            if(tree1[i] + tree2[j] == target) return true;
            else if(tree1[i] + tree2[j] < target) i++;
            else j--; 
            
        }
        
        return false;
    }
};


/*Test Cases


[1,2,3,4, null, null, null,5]
[1]
5
[999999999, 999999999, 999999999, 999999999]
[999999999,1,7]
999999999999
[515078126,-13169447,655245616,-23051700,null,null,null,-624732602]
[-739484763,null,144397080]
-434317703
[-300988154,null,740140743,697166207,818410759,null,null,null,936731239]
[-177861296,-534957072,127474120]
-478849450
[-98886296,-356725102,653883913,-636525858,-311701849,338240365,994048823,-744474454,-491146362,-336747411,-121412585,286534036,602295261,930983032,null,-862678772,-706957928,-610408158,-427671065,-351706054,-319507417,-199913152,null,-55080716,331727817,594588190,null,809685427,932337893,-966591604,-768781586,-735038789,-678836550,null,-558027253,-428420470,-393842654,null,null,null,-319499272,-269912701,-192184108,-87993345,243948705,324633507,null,463428212,null,723279489,824138011,null,964168499,null,-958057125,-835114923,null,null,null,-701971497,-660483111,-591607327,-515486247,-463437992,null,-395621619,null,null,null,null,-205354843,null,null,-97463997,null,-25566641,272900730,null,null,393739867,531512443,706569817,724577443,811034473,849504834,null,null,null,-875225488,-855235524,null,null,null,-661233095,null,null,null,null,null,-482150460,-438862675,-422408849,null,-260210303,null,null,null,-32270593,37498931,264291679,null,376616589,400505842,510183715,580325568,692281163,null,null,753577272,null,null,827323472,867464974,-889063004,null,null,null,-662227398,null,null,null,null,null,null,-409720075,null,-257135501,null,null,-4199221,182274794,null,null,364139545,null,null,null,null,null,565490578,588231890,null,null,739701999,804802027,null,831190777,null,null,null,null,null,null,null,null,null,null,-13601827,null,104433211,236779747,null,null,537349409,null,null,null,null,745177379,null,null,null,null,null,null,null,122961237,183163702,null,null,544440843,null,null,null,null,null,230078977]
[-339564463,-823424662,-120749486,-925620933,-638726996,-147071525,16697248,null,null,-690748833,-481794679,-169683911,null,-59845201,125031942,-785177739,-639876728,null,-375372546,-302026476,-149483160,null,null,null,434894007,null,null,null,null,null,-366835460,-335557117,null,-151562699,null,399059437,523493345,null,null,null,null,null,null,173525945,null,null,637083411,null,337090692,null,665900106,224497969,null,null,972472965,null,null,666546664]
443025491

*/
