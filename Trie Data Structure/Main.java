import java.util.*;
public class Main
{
    static class TrieNode
    {
        Map<Character,TrieNode> mp;             
        boolean isEndOfWord;                        // Declaring variables of Trie node
        TrieNode()              
        {                                           // Initializing variables
            mp = new HashMap<>();
            isEndOfWord = false;
        }
    }
    static TrieNode root = new TrieNode();
    public static void insert(String word)            // inserting new word in Structure
    {
        TrieNode itr = root;
        for(int i=0;i<word.length();i++)
        {
            TrieNode node = itr.mp.get(word.charAt(i));
            if(node == null)
            {
                TrieNode newNode = new TrieNode();
                itr.mp.put(word.charAt(i),newNode);
            }
            itr = itr.mp.get(word.charAt(i));
            
        }
        itr.isEndOfWord = true;
    }
    public static boolean search(String word)        // Searching word in Structure
    {
        TrieNode itr = root;
        for(int i=0;i<word.length();i++)
        {
            TrieNode node = itr.mp.get(word.charAt(i));
            if(node != null)
            {
                itr = itr.mp.get(word.charAt(i));
            }
            else
            {
                return false;
            }
        }
        return itr.isEndOfWord;
    }
    public static void main(String[] args)
    {
        TrieNode root = new TrieNode();                 // Declaring a new TrieNode
        
        insert("Jatin");
        insert("Modi");
        System.out.println(search("Jatin"));           // prints true
        System.out.println(search("Sunny"));           // prints false
    }
}
