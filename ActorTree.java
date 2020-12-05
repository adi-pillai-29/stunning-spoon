//Adi Pillai - arp3np

/**
 * This is the class you will create
 * 
 * @author Your friendly CS professors
 *
 */
public class ActorTree {
	/**
	 * ActorTree has only one property, the root node
	 */
	Node root;

	/**
	 * Initialize the root node in the default constructor
	 */
	public ActorTree() {
		this.root = new Node();
	}

	/**
	 * 
	 * @param name
	 *            - the name to find
	 * @return the matching Actor object
	 */
	public Actor find(String name) {
		if (this.isEmpty()) {
			return null;
		} else if(this.root.actor == null) 
			return null;
		else 
			return this.root.find(name); //recursive method for tri nodes that determines size
	}

	/**
	 * 
	 * @return an int representing 1 for each node in the tree
	 * 
	 */
	public int size() {
		if (this.isEmpty()) {
			return 0;
		} else {
			return this.root.size(); //recursive method for tri nodes that determines size
		}
	}

	/**
	 * 
	 * @return an int representing the maximum height of any branch
	 */
	public int height() {
		if(this.isEmpty())
			return 0;
		else
			return this.root.height();
	}

	/**
	 * an empty tree is one with no data
	 * 
	 * @return boolean - True if the tree is empty
	 */
	public boolean isEmpty() {
		return root == null; 	
	}

	/**
	 * 
	 * @param a
	 *            - an Actor object
	 * @return boolean - True if the element was inserted
	 */
	public boolean insert(Actor a) {
		if (this.root.actor == null) {
			Node n = new Node(a);
			this.root = n;
			return true;
		} else if(this.root.actor == null) 
			return false;
		else
			return this.root.insert(a); //recursive method for tri nodes that determines size
	}
	/**
	 * In order Traversal
	 */
	public String inOrder() {
		if(this.isEmpty())
			return "";
		else
			return this.root.inOrder();
	}
	/**
	 * The Node class is an inner class of the ActorTree This is a Binary Search
	 * Tree, so each Node will have left and right children
	 * 
	 * @author Your friendly CS Professors
	 *
	 */
	class Node {
		Actor actor;
		Node left;
		Node right;

		/**
		 * default constructor
		 */
		public Node() {
			actor = null;
			left = null;
			right = null;
			
		}

		/**
		 * Constructor that takes an Actor object
		 * 
		 * @param a
		 *            - an Actor left and right children are initialized to null
		 */
		public Node(Actor a) {
			this.actor = a;
			left = null;
			right = null;
		}

		/**
		 * The size method is recursive
		 * 
		 * @return an int to represent a count of all nodes
		 */
		public int size() { 
			if(this.actor == null)
				return 0;
			else if(this.left != null && this.right != null) {
				return 1 + this.left.size() + this.right.size();
			}
			else if(this.left != null)
				return 1 + this.left.size();
			else if(this.right != null)
				return 1 + this.right.size();
			else
				return 1;
		}


		/**
		 * The height method is recursive
		 * 
		 * @return an int to represent the maximum height of right or left child nodes,
		 *         plus 1 for the current node
		 */
		 public int height() {
			 if(this.actor == null)
					return 0;
			 if(this.right == null && this.left == null)
				 return 1;
			 else if(this.right == null)
				 return 1 + this.left.height();
			 else if(this.left == null)
				 return this.right.height();
			 else
				 return 1 + Math.max(this.left.height(), this.right.height());
		 }
		
		/**
		 * The insert method finds the best place to insert the Actor argument
		 * 
		 * @param a
		 *            - an Actor to insert
		 * @return boolean - True if the Actor argument was added, false otherwise
		 */
		public boolean insert(Actor a) {
			if(this.actor.equals(a)) 
				return false;
			else if (this.actor.compareTo(a) < 0)
				if(this.right == null) { //inserting the node if the right child is null
					Node n = new Node(a);
					this.right = n;
					return true;
				}
				else
					return this.right.insert(a); //continuing the recursive calls (not the base case)
			else if (this.actor.compareTo(a) > 0)
				if(this.left == null) { //inserting the node if the left child is null
					Node n = new Node(a);
					this.left = n;
					return true;
				}
				else
					return this.left.insert(a); //continuing recursive calls, not the base case)
			return false;
		}
			
		/**
		 * The find method returns an Actor object with a matching name
		 * 
		 * @param name
		 *            - the name to search for
		 * @return the searched for Actor, or null
		 */
		public Actor find(String name) {
			if(this.actor.getPrimaryName().equals(name)) //base case - returning the node that matches the node to be found 
				return this.actor;
			else if (this.actor.getPrimaryName().compareTo(name) < 0)
				 //look left
				return this.right.find(name); //all these different return statements can return that base case where the node to be found at some point in the recursion 
			else if (this.actor.getPrimaryName().compareTo(name) > 0)
				return this.left.find(name); //look right
			// ‘next’ points to left or right subtree
			return null; //not found 
		}
		
		public String inOrder() {
			String sum = "";
				if (this.left != null) {		//emphasis on left first 
					sum += this.left.inOrder(); //starting left, redefining tree with left as root calling in order, eventually adds the left that is a leaf/root w no children
				} //executes after leftmost node reached
				if (this.actor != null) { //base case
					sum += this.actor.toString() + "\n"; // when left is null, add the root
				} //reinitiating the process with right node as subtree
				if (this.right != null) {
					sum += this.right.inOrder(); // next instruction right, redefining tree with right as root ,calling in order (repeating instruction w/ order left, root,right - in order)
				}
			return sum; //returns to the node for example that pointed to the root node (a left node) of the innermost left node - reinitiates the bottom 2 if conditionals 
			//needs to be returned for recursive calls 
			/**
			String traversedNodes = "";
			if(this.left != null) {
				String traversedLeft = this.left.inOrder();
				if(this.right == null) {
					traversedNodes += traversedLeft + this.actor.toString() + "\n";
					return traversedNodes;
				}
				else if(this.right != null) {
					traversedNodes += traversedLeft + this.actor.toString() + "\n";
					String traversedRight = this.right.inOrder();
					traversedNodes += traversedRight + "\n";
					return traversedNodes;
				}
			}
			traversedNodes += this.actor.toString() + "\n";
			if(this.right == null) {
				return traversedNodes;
			}
			else
				traversedNodes += this.right.inOrder();
				return traversedNodes;
		**/
		}
		
		
	}
	
}
