
class Node{
    int value;
    Node left;
    Node right;

    public Node(int value){
        this.value = value;
        left = right = null;
    }
}
public class PerfectBinary {
    Node node;

    PerfectBinary(int value){
        node = new Node(value);
    }
    PerfectBinary(){
        node = null;
    }

    public static int depth(Node node){
        int d = 0;
        while (node != null){
            d += 1;
            node = node.left;
        }
        return d;
    }

    public static boolean perfect(Node node , int d , int l ){
        if(node == null){
            return true;
        }

        if(node.left == null && node.right == null){
            return d == l + 1;
        }

        if(node.left == null || node.right == null){
            return false;
        }

        return (perfect(node.left,d,l + 1) && perfect(node.right , d , l + 1));
    }


     public static void main(String[] args){
        Node root = null;
        root = new Node(2);
        root.left = new Node(3);
        root.right = new Node(4);
        root.right.right = new Node(7);
        System.out.println(depth(root));
        System.out.println(perfect(root, depth(root),0));
    }

}
