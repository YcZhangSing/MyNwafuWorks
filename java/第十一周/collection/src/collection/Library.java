package collection;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/**
 * ��������һ��ͼ��ݡ�
 *
 * Each book has:
 *    an ISBN (a unique identifier),
 *    a year of first publication,
 *    a list of authors
 *    a title (also unique)
 *    a rating (0.0 - 5.0)
 *
 */
public class Library {
    Map<Integer,Book> ISBNs = new HashMap<Integer,Book>();
    class Book{
        int isbn;
        int year;
        Set<String> authors;
        String title;
        float rating;
        public Book(int isbn, int year, Set<String> authors,  String title, float rating){
            this.isbn = isbn;
            this.year = year;
            this.authors = authors;
            this.title = title;
            this.rating = rating;
        }
    }
    /**
     * Add a new book to the library. If there exists a book with this ISBN,
     * do not modify this library.
     * ��ͼ������һ�����顣 ������ھ��д� ISBN ���鼮����Ҫ�޸Ĵ�ͼ��ݡ�
     * @
     * @param isbn The ISBN of the book (which uniquely identifies it)
     * @param year     the year that the book was first published
     * @param authors the authors of the book
     * @param title the title of the book (also unique)
     * @param rating the average reader rating for this book (0.0 - 5.0)
     * @return true if the book was added to the library, or false if the
     * book was not added (because there is already a book with that isbn)
     */
    public boolean addBook(int isbn, int year, Set<String> authors,  String title, float rating) {
        // FIXME complete this method
    	if(ISBNs.containsKey(isbn))
    	{
    		return false;
    	}
    	Book bk = new Book(isbn,year,authors,title,rating);
    	ISBNs.put(isbn, bk);
        return true;
    }


    /**
     * Remove the book with the given isbn from the library.
     * If no book with the given name exists, do not modify the library.
     * ��ͼ�����ɾ�����и��� isbn ���顣��������ھ��и������Ƶ��鼮���벻Ҫ�޸�ͼ��ݡ�
     * @param isbn The ISBN of the book (which uniquely identifies it)
     * @return true if the removal was successful, otherwise false
     */
    public boolean deleteBook(int isbn) {
    	
        // FIXME complete this method
    	if(!ISBNs.containsKey(isbn))
    	{
    		return false;
    	}
    	ISBNs.remove(isbn);
        return true;
    }

    /**
     * @return the total number of books in this library
     */
    public int getBookCount() {
        // FIXME complete this method
    	int a=ISBNs.size();
        return a;
    }

    /**
     * Get the titles of all books in the library that have a rating greater
     * than or equal to the rating provided.
     * ��ȡͼ��������ִ��ڻ�����ṩ�����ֵ������鼮��������
     * @param rating Only include books with a rating greater than or equal
     *                to this number.
     * @return the names of all books with a rating greater than or equal to
     * the argument rating
     */
    public Set<String> getTopBooks(float rating) {
    
        // FIXME complete this method
    	Set<String> hs = new HashSet<String>();
    	for(int i:ISBNs.keySet())
    	{
    		if(ISBNs.get(i).rating>=rating)
    		{
    			hs.add(ISBNs.get(i).title);
    		}
    	}
    	return hs;
    }

    /**
     * Get the names of all books that were written by a particular person.
     * If the given person has not written any book in the library,
     * return an empty set.
     * ��ȡ���ض���д�������鼮�����ơ������������û����ͼ���д���κ��飬�򷵻�һ���ռ���
     * @param author the name of a author
     * @return the names of all books for which the given person was an author
     */
    public Set<String> getAuthorBooks(String author) {
        // FIXME complete this method
    	Set<String> hs = new HashSet<String>();
    	for(int i:ISBNs.keySet())
    	{
    		for(String p : ISBNs.get(i).authors )
    		{
    			if(p.equals(author))
    			{
    				hs.add(ISBNs.get(i).title);
    			}
    		}
    	}
    	return hs;
    }

    /**
     * Gets the total number of unique authors across all books in this library.
     * Each author is only counted once, even if they have written multiple
     * books.
     * ��ȡ��ͼ����е�����������ÿ������ֻ����һ�Σ���ʹ����д�˶౾�顣
     * For example, if there are four books in the library:
     * 439023483, 2008, "The Hunger Games", 4.34, authors: "Suzanne Collins"
     * 439023491, 2009, "Catching Fire", 4.3, authors: "Suzanne Collins"
     * 439023513, 2010, "Mockingjay", 4.03, authors: "Suzanne Collins"
     * 60764899, 1950, "The Lion, the Witch and the Wardrobe", 4.19, authors: "C.S. Lewis"
     * 61234001, 2005, "Freakonomics: A Rogue Economist Explores the Hidden Side of Everything", 3.93, authors: "Steven D. Levitt", "Stephen J. Dubner"
     * then getNumAuthors() == 4.
     *
     * @return the number of unique authors across all books
     */
    public int getNumAuthors() {
        // FIXME complete this method
    	Set<String> hs = new HashSet<String>();
    	for(int i:ISBNs.keySet())
    	{
    		for(String p :ISBNs.get(i).authors)
    		{
    			hs.add(p);
    		}
    	}
    	return hs.size();
    	
    
    }

    /**
     * Checks whether two people are co-authors (they were authors of the same book).
     * ����������Ƿ��Ǻ����ߣ�������ͬһ��������ߣ���
     * @return true if person1 and person2 are both authors of the same book
     */
    public boolean areCoAuthors(String person1, String person2) {
        // FIXME complete this method
    	//String p2 = new String();
    	for(int i:ISBNs.keySet())
    	{
    		for(String p : ISBNs.get(i).authors )
    		{
    			if(p.equals(person1))
    			{
    				if(ISBNs.get(i).authors .contains(person2))
    				{
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }

    /**
     * �������߳����ͼ������鼮�ĵ�һ�꣬������ǲ��Ǵ�ͼ������κ��鼮�����ߣ���Ϊ -1��
     * @return the first year in which the given author published a book
     * that is in this library, or -1 if they were not an author of any
     * book in this library.
     */
    public int getFirstPublishYear(String personName) 
    {
    	int year = 100000;
    	for(int i:ISBNs.keySet())
    	{
    		if(ISBNs.get(i).authors.contains(personName))
    		{
    			int t = ISBNs.get(i).year;
    			if(t<year)
    			{
    				year=t;
    			}
    		}
    	}
    	if(year == 100000)
    		return -1;
    	return year;
    }
    
        

    /**
     * Gets the maximum number of unique co-authors of any author.
     * ���غ��������������ߵĺ�������
     * Only unique co-authors are counted i.e. if two authors co-author
     * multiple books, this only adds one towards the total number
     * of co-authors.
     * <p>
     * For example, if there are eight books in the library:
     *
     * 743477111, 1595, "An Excellent conceited Tragedie of Romeo and Juliet", 3.73, authors: "William Shakespeare", "Robert Jackson", "Rex Gibson"
     * 521618746, 1600, "The Tragicall Historie of Hamlet, Prince of Denmark"	4, authors: "William Shakespeare", "Richard Andrews", "Rex Gibson"
     * 743477103, 1606, "The Tragedy of Macbeth", 3.88, authors: William Shakespeare
     * 743477545, 1595, "A Midsummer Night's Dream", 3.94, authors: "William Shakespeare", "Barbara A. Mowat", "Paul Werstine", "Catherine Belsey"
     * 679783261, 1813, "Pride and Prejudice", 4.24, authors: "Jane Austen"
     * 141439661, 1811, "Sense and Sensibility, 4.06, authors: "Jane Austen", "Tony Tanner", "Ros Ballaster"
     * 141439580, 1815, "Emma", 3.99, "Jane Austen", "Fiona Stafford"
     * 192802631, 1817, "Persuasion",	4.13, "Jane Austen", "James Kinsley", "Deidre Shauna Lynch"
     *
     * then getMaxCoAuthors would return 6, which is the number of unique
     * co-authors for William Shakespeare in that library.  Notice that
     * "Rex Gibson" co-authors on two books, but is only counted once.
     *
     * @return the maximum number of co-authors for any author
     */
    public int getMaxCoauthors() {
        // FIXME complete this method
    	String p1=new String();
    	String p2 = new String();
    	
    	Set<String> au = new HashSet<String>();
    	for(int i:ISBNs.keySet())
    	{
    		for(String p:ISBNs.get(i).authors)
    		{
    			au.add(p);
    		}
    	}
    	String [] auarry = (String [])au.toArray();
    	int [] a = new int[au.size()];
    	int t=0;
    	for(;t<au.size()-1;++t)
    	{
    		for(int j=t+1;j<au.size();++j)
    		{
    			if(this.areCoAuthors(auarry[t], auarry[j]))
    			{
    				a[t]++;
    				a[j]++;
    			}
    		}
    	}
    	int max=0;
    	for(int i=0;i<au.size();++i)
    	{
    		if(a[i]>max)
    		{
    			max=a[i];
    		}
    	}
        return max;
    }
}
