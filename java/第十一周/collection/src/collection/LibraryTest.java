package collection;


import org.junit.Before;
import org.junit.FixMethodOrder;
import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.Timeout;
import org.junit.runners.MethodSorters;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import static org.junit.Assert.*;

@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class LibraryTest {
    @Rule
    public Timeout globalTimeout = Timeout.millis(1000);

    Library library;

    static final int INITIAL = 50;
    static final int LARGER = 200;

    @Before
    public void setup() {
        library = new Library();
        addInitialBooks();
    }

    @Test
    public void testGetBookCount() {
        Library empty = new Library();
        assertEquals("getBookCount() returned incorrect number of Books for empty library", 0, empty.getBookCount());
        assertEquals("getBookCount() returned incorrect number of Books", INITIAL, library.getBookCount());
        addMoreBooks();
        assertEquals("getBookCount() returned incorrect number of Books", LARGER, library.getBookCount());
    }

    @Test
    public void testGetBookCountDuplicate() {
        addInitialBooks();
        assertEquals("getBookCount() returned incorrect number of Books", INITIAL, library.getBookCount());
        addMoreBooks();
        addMoreBooks();
        assertEquals("getBookCount() returned incorrect number of Books", LARGER, library.getBookCount());
    }

    @Test
    public void testGetBookCountDelete() {
        Library empty = new Library();
        final int NON_EXISTENT_ARTICLE = 1234567;
        library.deleteBook(NON_EXISTENT_ARTICLE);
        assertEquals("getBookCount() returned incorrect number of Books for empty library", 0, empty.getBookCount());
        int isbn = Integer.parseInt(books[0][0]);
        assertTrue(library.deleteBook(isbn));
        assertFalse(library.deleteBook(isbn));
        assertEquals("getBookCount() returned incorrect number of Books", INITIAL-1, library.getBookCount());
    }

    private boolean checkStringSet(Set<String> out, String[] expected) {
        boolean sound = false;
        if (out.size() == expected.length) {
            sound = true;
            for (String s : expected) {
                if (!out.contains(s))
                    sound = false;
            }
        }
        return sound;
    }

    @Test
    public void testGetTopBooks() {
        Set<String> out = library.getTopBooks(0f); // all
        assertTrue("Incorrect getTopBooks(0).  Expected to get all "+INITIAL+" books but got "+out.size(), out.size() == INITIAL);

        out = library.getTopBooks(5f); // all
        assertTrue("Incorrect getTopBooks(5).  Expected to get no books but got "+out.size(), out.size() == 0);

        String[] t45 = {"Harry Potter and the Deathly Hallows", "Harry Potter and the Half-Blood Prince", "Harry Potter and the Prisoner of Azkaban", "Harry Potter and the Goblet of Fire"};
        out = library.getTopBooks(4.5f);
        assertTrue("Incorrect getTopBooks(4.5f).  Expected "+Arrays.toString(t45)+" but got "+out, checkStringSet(out, t45));

        addMoreBooks();
        String[] t455 = {"Harry Potter and the Deathly Hallows", "The Name of the Wind"};
        out = library.getTopBooks(4.55f);
        assertTrue("Incorrect getTopBooks(4.55f).  Expected "+Arrays.toString(t455)+" but got "+out, checkStringSet(out, t455));
    }

    @Test
    public void testGetTopBooksDuplicate() {
        addInitialBooks();
        Set<String> out = library.getTopBooks(0f); // all
        assertTrue("Incorrect getTopBooks(0).  Expected to get all "+INITIAL+" books but got "+out.size(), out.size() == INITIAL);

        out = library.getTopBooks(5f); // all
        assertTrue("Incorrect getTopBooks(5).  Expected to get no books but got "+out.size(), out.size() == 0);

        String[] t45 = {"Harry Potter and the Deathly Hallows", "Harry Potter and the Half-Blood Prince", "Harry Potter and the Prisoner of Azkaban", "Harry Potter and the Goblet of Fire"};
        out = library.getTopBooks(4.5f);
        assertTrue("Incorrect getTopBooks(4.5f).  Expected "+Arrays.toString(t45)+" but got "+out, checkStringSet(out, t45));

        addMoreBooks();
        addMoreBooks();
        String[] t455 = {"Harry Potter and the Deathly Hallows", "The Name of the Wind"};
        out = library.getTopBooks(4.55f);
        assertTrue("Incorrect getTopBooks(4.55f).  Expected "+Arrays.toString(t455)+" but got "+out, checkStringSet(out, t455));
    }

    @Test
    public void testGetTopBooksDelete() {
        library.deleteBook(545010225);

        String[] t45 = {"Harry Potter and the Half-Blood Prince", "Harry Potter and the Prisoner of Azkaban", "Harry Potter and the Goblet of Fire"};
        Set<String> out = library.getTopBooks(4.5f);
        assertTrue("Incorrect getTopBooks(4.5f).  Expected "+Arrays.toString(t45)+" but got "+out, checkStringSet(out, t45));

        addMoreBooks();
        String[] t455 = {"The Name of the Wind"};
        out = library.getTopBooks(4.55f);
        assertTrue("Incorrect getTopBooks(4.55f).  Expected "+Arrays.toString(t455)+" but got "+out, checkStringSet(out, t455));
    }

    private void checkAuthor(String author, Set<String> expected) {
        assertEquals("getAuthorBooks(\"" + author + "\") returned incorrect set", expected, library.getAuthorBooks(author));
    }

    @Test
    public void testGetAuthorBooks() {
        checkAuthor("Friedrich Nietzsche", Set.of());
        checkAuthor("Jane Austen", Set.of("Pride and Prejudice"));
        checkAuthor("John Grisham", Set.of());
        checkAuthor("Louisa May Alcott", Set.of("Little Women"));
        addMoreBooks();
        checkAuthor("John Grisham", Set.of("The Firm", "A Time to Kill"));
        checkAuthor("Jane Austen", Set.of("Pride and Prejudice", "Sense and Sensibility", "Emma"));
    }

    @Test
    public void testGetAuthorBooksDuplicate() {
        addMoreBooks();
        addInitialBooks();
        addMoreBooks();
        checkAuthor("Jane Austen", Set.of("Pride and Prejudice", "Sense and Sensibility", "Emma"));
    }

    @Test
    public void testGetAuthorBooksDelete() {
        addMoreBooks();
        checkAuthor("Jane Austen", Set.of("Pride and Prejudice", "Sense and Sensibility", "Emma"));
        library.deleteBook(679783261);
        checkAuthor("Jane Austen", Set.of("Sense and Sensibility", "Emma"));
        library.deleteBook(141439661);
        checkAuthor("Jane Austen", Set.of("Emma"));
        checkAuthor("John Grisham", Set.of("The Firm", "A Time to Kill"));
        library.deleteBook(385338600);
        checkAuthor("John Grisham", Set.of("The Firm"));
    }

    @Test
    public void testGetNumAuthors() {
        assertEquals("getNumAuthors() returned incorrect value", 48, library.getNumAuthors());
        addMoreBooks();
        assertEquals("getNumAuthors() returned incorrect value", 199, library.getNumAuthors());
    }

    @Test
    public void testGetNumAuthorsDuplicate() {
        addInitialBooks();
        assertEquals("getNumAuthors() returned incorrect value", 48, library.getNumAuthors());
        addMoreBooks();
        addMoreBooks();
        assertEquals("getNumAuthors() returned incorrect value", 199, library.getNumAuthors());
    }

    @Test
    public void testGetNumAuthorsDelete() {
        library.deleteBook(739326228);
        assertEquals("getNumAuthors() returned incorrect value", 47, library.getNumAuthors());
        library.deleteBook(61120081);
        assertEquals("getNumAuthors() returned incorrect value", 46, library.getNumAuthors());
        addMoreBooks();
        library.deleteBook(345391802);
        assertEquals("getNumAuthors() returned incorrect value", 196, library.getNumAuthors());
    }

    private void checkCoAuthors(String person1, String person2, boolean expected) {
        boolean result = library.areCoAuthors(person1, person2);
        assertTrue("areCoAuthors(\"" + person1 + "\", \"" + person2 + "\") returned " + result + ", expected " + expected, expected == result);
    }

    @Test
    public void testAreCoAuthors() {
        checkCoAuthors("George Orwell", "Erich Fromm", true);
        checkCoAuthors("J.K. Rowling", "Mary GrandPré", true);
        checkCoAuthors("Roald Dahl", "Quentin Blake", false);
        checkCoAuthors("Leo Tolstoy", "Louise Maude", false);
        checkCoAuthors("Kami Garcia", "Margaret Stohl", false);
        addMoreBooks();
        checkCoAuthors("Roald Dahl", "Quentin Blake", true);
        checkCoAuthors("Leo Tolstoy", "Louise Maude", true);
        checkCoAuthors("Kami Garcia", "Margaret Stohl", true);
    }

    @Test
    public void testAreCoAuthorsDelete() {
        addMoreBooks();
        checkCoAuthors("Roald Dahl", "Quentin Blake", true);
        library.deleteBook(142403881);
        checkCoAuthors("Roald Dahl", "Quentin Blake", true);
        library.deleteBook(141301066);
        checkCoAuthors("Roald Dahl", "Quentin Blake", false);

        checkCoAuthors("Leo Tolstoy", "Louise Maude", true);
        library.deleteBook(345803922);
        checkCoAuthors("Leo Tolstoy", "Louise Maude", false);

        checkCoAuthors("Kami Garcia", "Margaret Stohl", true);
        library.deleteBook(316042676);
        checkCoAuthors("Kami Garcia", "Margaret Stohl", false);
    }

    @Test
    public void testGetFirstPublishYearNull() {
        checkPublishYear("Friedrich Nietzsche", -1);
        checkPublishYear("Jeanne DuPrau", -1);
        checkPublishYear("Stephen King", -1);
        addMoreBooks();
        checkPublishYear("Stephen King", 1977);
    }

    @Test
    public void testGetFirstPublishYear() {
        checkPublishYear("Jane Austen", 1813);
        checkPublishYear("J.K. Rowling", 1997);
        addMoreBooks();
        checkPublishYear("Jane Austen", 1811);
        checkPublishYear("J.K. Rowling", 1997);
    }

    @Test
    public void testGetFirstPublishYearDelete() {
        addMoreBooks();
        checkPublishYear("Jane Austen", 1811);
        checkPublishYear("J.K. Rowling", 1997);
        library.deleteBook(141439661);
        checkPublishYear("Jane Austen", 1813);
        library.deleteBook(439554934);
        checkPublishYear("J.K. Rowling", 1998);
    }

    private void checkPublishYear(String person, int expected) {
        int result = library.getFirstPublishYear(person);
        assertTrue("getFirstBookYear(\"" + person + "\") returned " + result + ", expected " + expected, expected == result);
    }


//    @Test
//    public void testGetMaxBooks() {
//        assertEquals("getMaxBooks() returned incorrect value", 7, library.getMaxBooks());
//        addMoreBooks();
//        assertEquals("getMaxBooks() returned incorrect value", 7, library.getMaxBooks());
//    }

//    @Test
//    public void testGetMaxBooksDuplicate() {
//        addInitialBooks();
//        assertEquals("getMaxBooks() returned incorrect value", 7, library.getMaxBooks());
//        addMoreBooks();
//        addMoreBooks();
//        assertEquals("getMaxBooks() returned incorrect value", 7, library.getMaxBooks());
//    }

//    @Test
//    public void testGetMaxBooksDelete() {
//        library.deleteBook(439554934);
//        library.deleteBook(43965548);
//        library.deleteBook(439358078);
//        assertEquals("getMaxBooks() returned incorrect value", 4, library.getMaxBooks());
//        library.deleteBook(439064864);
//        addMoreBooks();
//        assertEquals("getMaxBooks() returned incorrect value", 5, library.getMaxBooks());
//    }

    private void addBooks(int start, int end) {
        for (int i = start; i < end; i++) {
            int isbn = Integer.parseInt(books[i][0]);
            int year = Integer.parseInt(books[i][1]);
            float rating = Float.parseFloat(books[i][2]);
            String title = books[i][3];
            Set<String> authors = new HashSet<>(Arrays.asList(books[i][4].split(", ")));
            library.addBook(isbn, year, authors, title, rating);
        }
    }

    private void addInitialBooks() {
        addBooks(0, INITIAL);
    }

    private void addMoreBooks() {
        addBooks(50,LARGER);
    }


    String[][] books = {
            {"439023483","2008","4.34","The Hunger Games","Suzanne Collins"},
            {"439554934","1997","4.44","Harry Potter and the Philosopher's Stone","J.K. Rowling, Mary GrandPré"},
            {"316015849","2005","3.57","Twilight","Stephenie Meyer"},
            {"61120081","1960","4.25","To Kill a Mockingbird","Harper Lee"},
            {"743273567","1925","3.89","The Great Gatsby","F. Scott Fitzgerald"},
            {"525478817","2012","4.26","The Fault in Our Stars","John Green"},
            {"618260307","1937","4.25","The Hobbit or There and Back Again","J.R.R. Tolkien"},
            {"316769177","1951","3.79","The Catcher in the Rye","J.D. Salinger"},
            {"1416524797","2000","3.85","Angels & Demons ","Dan Brown"},
            {"679783261","1813","4.24","Pride and Prejudice","Jane Austen"},
            {"1594480001","2003","4.26","The Kite Runner ","Khaled Hosseini"},
            {"62024035","2011","4.24","Divergent","Veronica Roth"},
            {"451524934","1949","4.14","Nineteen Eighty-Four","George Orwell, Erich Fromm, Celâl Üster"},
            {"452284244","1945","3.87","Animal Farm: A Fairy Story","George Orwell"},
            {"553296981","1947","4.1","Het Achterhuis: Dagboekbrieven 14 juni 1942 - 1 augustus 1944","Anne Frank, Eleanor Roosevelt, B.M. Mooyaart-Doubleday"},
            {"307269752","2005","4.11","Män som hatar kvinnor","Stieg Larsson, Reg Keeland"},
            {"439023491","2009","4.3","Catching Fire","Suzanne Collins"},
            {"043965548","1999","4.53","Harry Potter and the Prisoner of Azkaban","J.K. Rowling, Mary GrandPré, Rufus Beck"},
            {"618346252","1954","4.34"," The Fellowship of the Ring","J.R.R. Tolkien"},
            {"439023513","2010","4.03","Mockingjay","Suzanne Collins"},
            {"439358078","2003","4.46","Harry Potter and the Order of the Phoenix","J.K. Rowling, Mary GrandPré"},
            {"316166685","2002","3.77","The Lovely Bones","Alice Sebold"},
            {"439064864","1998","4.37","Harry Potter and the Chamber of Secrets","J.K. Rowling, Mary GrandPré"},
            {"439139600","2000","4.53","Harry Potter and the Goblet of Fire","J.K. Rowling, Mary GrandPré"},
            {"545010225","2007","4.61","Harry Potter and the Deathly Hallows","J.K. Rowling, Mary GrandPré"},
            {"307277674","2003","3.79","The Da Vinci Code","Dan Brown"},
            {"439785960","2005","4.54","Harry Potter and the Half-Blood Prince","J.K. Rowling, Mary GrandPré"},
            {"140283331","1954","3.64","Lord of the Flies ","William Golding"},
            {"743477111","1595","3.73","An Excellent conceited Tragedie of Romeo and Juliet","William Shakespeare, Robert           Jackson"},
            {"297859382","2012","4.03","Gone Girl","Gillian Flynn"},
            {"399155341","2009","4.45","The Help","Kathryn Stockett"},
            {"142000671","1937","3.84","Of Mice and Men ","John Steinbeck"},
            {"739326228","1997","4.08","Memoirs of a Geisha","Arthur Golden"},
            {"1612130291","2011","3.67","Fifty Shades of Grey","E.L. James"},
            {"61122416","1988","3.82","O Alquimista","Paulo Coelho, Alan R. Clarke"},
            {"385732554","1993","4.12","The Giver","Lois Lowry"},
            {"60764899","1950","4.19","The Lion, the Witch and the Wardrobe","C.S. Lewis"},
            {"965818675","2003","3.95","The Time Traveler's Wife","Audrey Niffenegger"},
            {"553588486","1996","4.45","A Game of Thrones","George R.R. Martin"},
            {"143038419","2006","3.51","Eat, pray, love: one woman's search for everything across Italy, India and Indonesia","Elizabeth Gilbert"},
            {"786838655","2005","4.23","The Lightning Thief","Rick Riordan"},
            {"451529308","1868","4.04","Little Women","Louisa May Alcott"},
            {"142437204","1847","4.1","Jane Eyre","Charlotte Brontë, Michael Mason"},
            {"553816713","1996","4.06","The Notebook","Nicholas Sparks"},
            {"770430074","2001","3.88","Life of Pi","Yann Martel"},
            {"1565125606","2006","4.07","Water for Elephants","Sara Gruen"},
            {"375831002","2005","4.36","The Book Thief","Markus Zusak"},
            {"307347974","1953","3.97","Fahrenheit 451","Ray Bradbury"},
            {"316160199","2006","3.52","New Moon (Twilight, #2)","Stephenie Meyer"},
            {"60513039","1974","4.29","Where the Sidewalk Ends: The Poems and Drawings of Shel Silverstein","Shel Silverstein"},
            {"1416914285","2007","4.12","City of Bones","Cassandra Clare"},
            {"316160202","2007","3.69","Eclipse","Stephenie Meyer"},
            {"375826696","2002","3.86","Eragon","Christopher Paolini"},
            {"345391802","1979","4.2","The Hitchhiker's Guide to the Galaxy","Douglas Adams"},
            {"60929871","1932","3.97","Brave New World","Aldous Huxley"},
            {"031606792","2008","3.7","Breaking Dawn","Stephenie Meyer"},
            {"142001740","2001","4.01","The Secret Life of Bees","Sue Monk Kidd"},
            {"142437174","1884","3.8","The Adventures of Huckleberry Finn","Mark Twain, John Seelye, Guy Cardwell"},
            {"64410935","1952","4.15","Charlotte's Web","E.B. White, Garth Williams, Rosemary Wells"},
            {"1400032717","2003","3.85","The Curious Incident of the Dog in the Night-Time","Mark Haddon"},
            {"1594633665","2015","3.88","The Girl on the Train","Paula Hawkins"},
            {"679879242","1995","3.94","Northern Lights","Philip Pullman"},
            {"393978893","1847","3.82","Wuthering Heights","Emily Brontë, Richard J. Dunn"},
            {"743454537","2004","4.06","My Sister's Keeper","Jodi Picoult"},
            {"385333846","1969","4.06","Slaughterhouse-Five, or The Children's Crusade: A Duty-Dance with Death ","Kurt Vonnegut Jr."},
            {"446675539","1936","4.28","Gone with the Wind","Margaret Mitchell"},
            {"1594489505","2007","4.34","A Thousand Splendid Suns","Khaled Hosseini"},
            {"671027344","1999","4.21","The Perks of Being a Wallflower","Stephen Chbosky"},
            {"7442912","2012","4.07","Insurgent","Veronica Roth"},
            {"812550706","1985","4.3","Ender's Game","Orson Scott Card"},
            {"141439475","1818","3.75","Frankenstein; or, The Modern Prometheus","Mary Wollstonecraft Shelley, Percy Bysshe Shelley, Maurice Hindle"},
            {"450040186","1977","4.17","The Shining","Stephen King"},
            {"316068047","2008","3.84","The Host","Stephenie Meyer"},
            {"142402516","2005","4.09","Looking for Alaska","John Green"},
            {"014028009","1996","3.75","","Helen Fielding"},
            {"141439661","1811","4.06","Sense and Sensibility","Jane Austen, Tony Tanner, Ros Ballaster"},
            {"439244196","1998","3.93","Holes","Louis Sachar, Louis Sachar"},
            {"307275558","2003","3.7","The Devil Wears Prada","Lauren Weisberger"},
            {"143039954","-720","3.73","Ὀδύσσεια","Homer, Robert Fagles, E.V. Rieu, Frédéric Mugler, Bernard Knox"},
            {"156012197","1946","4.28","Le Petit Prince","Antoine de Saint-Exupéry, Richard Howard, Dom Marcos Barbosa, Melina Karakosta"},
            {"074324754","2005","4.24","The Glass Castle","Jeannette Walls"},
            {"385486804","1996","3.94","Into the Wild","Jon Krakauer"},
            {"141439602","1859","3.81","A Tale of Two Cities","Charles Dickens, Richard Maxwell, Hablot Knight Browne"},
            {"030734813","1990","3.96","Jurassic Park","Michael Crichton"},
            {"60256656","1964","4.38","The Giving Tree","Shel Silverstein"},
            {"385338600","1989","4.03","A Time to Kill","John Grisham"},
            {"374500010","1958","4.3","Un di Velt Hot Geshvign","Elie Wiesel, Marion Wiesel"},
            {"014241493","2008","3.88","Paper Towns","John Green"},
            {"345418263","1973","4.25","The Princess Bride","William Goldman"},
            {"014038572","1967","4.06","The Outsiders","S.E. Hinton"},
            {"385737947","2009","4.02","The Maze Runner","James Dashner"},
            {"61234001","2005","3.93","Freakonomics: A Rogue Economist Explores the Hidden Side of Everything","Steven D. Levitt, Stephen J. Dubner"},
            {"517189607","1911","4.12","The Secret Garden","Frances Hodgson Burnett"},
            {"60531045","1967","4.04","Cien años de soledad","Gabriel García Márquez, Gregory Rabassa"},
            {"375751513","1891","4.06","The Picture of Dorian Gray","Oscar Wilde, Jeffrey Eugenides"},
            {"345803507","2012","3.88","Fifty Shades Freed","E.L. James"},
            {"393970124","1897","3.98","Dracula","Bram Stoker, Nina Auerbach, David J. Skal"},
            {"307269981","2006","4.22","Flickan som lekte med elden","Stieg Larsson, Reg Keeland"},
            {"1612130585","2011","3.87","Fifty Shades Darker","E.L. James"},
            {"60786507","1998","4.02","The Poisonwood Bible","Barbara Kingsolver"},
            {"349113912","2000","3.97","Me Talk Pretty One Day","David Sedaris"},
            {"99408392","1963","4.22","Where the Wild Things Are","Maurice Sendak"},
            {"140449264","1844","4.21","Le Comte de Monte-Cristo","Alexandre Dumas, Robin Buss"},
            {"307265439","2006","3.95","The Road","Cormac McCarthy"},
            {"7524277","2013","3.63","Allegiant","Veronica Roth"},
            {"446693804","1999","4.15","A Walk to Remember","Nicholas Sparks"},
            {"440241413","2000","3.61","Confessions of a Shopaholic","Sophie Kinsella"},
            {"451525264","1862","4.14","Les Misérables","Victor Hugo, Lee Fahnestock, Norman MacAfee"},
            {"553381695","1998","4.4","A Clash of Kings","George R.R. Martin"},
            {"143037145","2005","3.64","The Memory Keeper's Daughter","Kim Edwards"},
            {"670026603","2012","4.27","Me Before You","Jojo Moyes"},
            {"684833395","1961","3.98","Catch-22","Joseph Heller"},
            {"751529818","1997","4.06","Tuesdays with Morrie","Mitch Albom, Saulius Dagys"},
            {"312422156","2002","3.98","Middlesex","Jeffrey Eugenides"},
            {"143039563","1876","3.89","The Adventures of Tom Sawyer","Mark Twain, Guy Cardwell, John Seelye"},
            {"440498058","1962","4.04","A Wrinkle in Time","Madeleine L'Engle"},
            {"143038095","1989","3.9","The Joy Luck Club","Amy Tan"},
            {"038549081","1985","4.06","The Handmaid's Tale","Margaret Atwood"},
            {"385729332","2001","3.75","The Sisterhood of the Traveling Pants","Ann Brashares"},
            {"60987103","1995","3.52","Wicked: The Life and Times of the Wicked Witch of the West","Gregory Maguire, Douglas Smith"},
            {"582418275","1991","3.99","The Firm","John Grisham"},
            {"316098337","2010","4.03","Room","Emma Donoghue"},
            {"521618746","1600","4","The Tragicall Historie of Hamlet, Prince of Denmark","William Shakespeare, Richard Andrews, Rex Gibson"},
            {"340839937","1965","4.19","Dune","Frank Herbert"},
            {"316346624","2000","3.92","The Tipping Point: How Little Things Can Make a Big Difference","Malcolm Gladwell"},
            {"1451648537","2011","4.09","Steve Jobs","Walter Isaacson"},
            {"451163966","1962","4.18","One Flew Over the Cuckoo's Nest","Ken Kesey"},
            {"684830493","1952","3.73","The Old Man and the Sea","Ernest Hemingway"},
            {"142000663","1939","3.92","The Grapes of Wrath","John Steinbeck"},
            {"1401308589","2003","3.9","The Five People You Meet in Heaven","Mitch Albom"},
            {"451528824","1908","4.23","Anne of Green Gables","L.M. Montgomery"},
            {"1416914307","2009","4.34","City of Glass","Cassandra Clare"},
            {"055357342","2000","4.54","A Storm of Swords","George R.R. Martin"},
            {"006075995","1996","3.79","Divine Secrets of the Ya-Ya Sisterhood","Rebecca Wells"},
            {"440242940","1991","4.2","Outlander","Diana Gabaldon"},
            {"142437263","1850","3.37","The Scarlet Letter","Nathaniel Hawthorne, Thomas E. Connolly, Nina Baym"},
            {"1594744769","2011","3.89","Miss Peregrine’s Home for Peculiar Children","Ransom Riggs"},
            {"030726999","2007","4.2","Luftslottet som sprängdes","Stieg Larsson, Reg Keeland"},
            {"804139024","2012","4.39","The Martian","Andy Weir"},
            {"451207149","1989","4.29","The Pillars of the Earth","Ken Follett"},
            {"1400064163","2010","4.4","Unbroken: A World War II Story of Survival, Resilience, and Redemption","Laura Hillenbrand"},
            {"671027387","2001","3.67","Deception Point","Dan Brown"},
            {"316055433","2013","3.87","The Goldfinch","Donna Tartt"},
            {"1595141715","2007","4.02","Thirteen Reasons Why","Jay Asher"},
            {"452287022","1999","3.85","Girl with a Pearl Earring","Tracy Chevalier"},
            {"525421033","2009","3.96","If I Stay","Gayle Forman"},
            {"312353766","1997","4.16","The Red Tent","Anita Diamant"},
            {"786856866","2006","4.23","The Sea of Monsters","Rick Riordan"},
            {"446528056","2006","4.01","Dear John","Nicholas Sparks"},
            {"1416914293","2008","4.21","City of Ashes","Cassandra Clare"},
            {"743477103","1606","3.88","The Tragedy of Macbeth","William Shakespeare"},
            {"618346260","1954","4.42","The Two Towers","J.R.R. Tolkien"},
            {"031232118","2004","3.83","Something Borrowed","Emily Giffin"},
            {"394800168","1960","4.29","Green Eggs and Ham","Dr. Seuss, לאה נאור"},
            {"142403881","1964","4.1","Charlie and the Chocolate Factory","Roald Dahl, Quentin Blake"},
            {"1423101464","2008","4.39","The Battle of the Labyrinth","Rick Riordan"},
            {"192833596","1860","3.75","Great Expectations","Charles Dickens"},
            {"345339738","1955","4.51","The Return of the King","J.R.R. Tolkien"},
            {"142311339","2010","4.35","The Lost Hero","Rick Riordan"},
            {"1250012570","2013","4.11","Eleanor & Park","Rainbow Rowell"},
            {"055358202","2005","4.1","A Feast for Crows","George R.R. Martin"},
            {"525423648","2010","3.68","Matched","Ally Condie"},
            {"747263744","2001","4.11","American Gods","Neil Gaiman"},
            {"385199570","1978","4.34","The Stand","Stephen King, Bernie Wrightson"},
            {"446547565","2008","4.14","The Last Song","Nicholas Sparks"},
            {"552151696","1998","3.6","Digital Fortress","Dan Brown"},
            {"141439580","1815","3.99","Emma","Jane Austen, Fiona Stafford"},
            {"345803922","1877","4.02","Анна Каренина","Leo Tolstoy, Louise Maude, Leo Tolstoj, Aylmer Maude"},
            {"393312836","1962","3.98","A Clockwork Orange","Anthony Burgess"},
            {"964729237","2007","3.74","The Shack: Where Tragedy Confronts Eternity","William Paul Young"},
            {"739380338","2009","4.5","The Last Olympian","Rick Riordan"},
            {"451169514","1986","4.18","It","Stephen King"},
            {"143058142","1866","4.18","Преступление и наказание","Fyodor Dostoyevsky, David McDuff"},
            {"61148512","1963","3.98","The Bell Jar","Sylvia Plath"},
            {"7205236","1996","4.07","Angela's Ashes: A Memoir","Frank McCourt"},
            {"553208845","1922","3.99","Siddhartha","Hermann Hesse, Hilda Rosner"},
            {"679745580","1965","4.05","In Cold Blood","Truman Capote"},
            {"316042676","2009","3.76","Beautiful Creatures","Kami Garcia, Margaret Stohl"},
            {"1416975861","2010","4.33","Clockwork Angel","Cassandra Clare"},
            {"141301066","1988","4.29","Matilda","Roald Dahl, Quentin Blake"},
            {"385534639","2011","4.03","The Night Circus","Erin Morgenstern"},
            {"743227441","2001","4.04","The Other Boleyn Girl","Philippa Gregory"},
            {"689865384","2005","3.86","Uglies","Scott Westerfeld"},
            {"618640150","1955","4.47","The Lord of the Rings","J.R.R. Tolkien"},
            {"307592731","2012","3.96","Wild: From Lost to Found on the Pacific Crest Trail ","Cheryl Strayed"},
            {"930289234","1987","4.35","Watchmen","Alan Moore, Dave Gibbons, John Higgins"},
            {"075640407","2007","4.55","The Name of the Wind","Patrick Rothfuss"},
            {"316017922","2008","4.11","Outliers: The Story of Success","Malcolm Gladwell"},
            {"142437247","1851","3.46","Moby Dick; or, The Whale","Herman Melville, Andrew Delbanco, Tom Quirk"},
            {"385340990","2008","4.12","The Guernsey Literary and Potato Peel Pie Society","Mary Ann Shaffer, Annie Barrows"},
            {"393327345","1996","4.2","Fight Club","Chuck Palahniuk"},
            {"441008534","2001","3.96","Dead Until Dark","Charlaine Harris"},
            {"671727796","1982","4.17","The Color Purple","Alice Walker"},
            {"739461192","2005","4.12","Marley & Me: Life and Love with the World's Worst Dog","John Grogan"},
            {"312330871","1939","4.23","Ten Little Niggers","Agatha Christie"},
            {"385504225","2009","3.66","The Lost Symbol","Dan Brown"},
            {"1416989412","2009","4","Hush, Hush","Becca Fitzpatrick"},
            {"1561797464","1843","4.02","A Christmas Carol","Charles Dickens"},
            {"345476875","1976","3.97","Interview with the Vampire","Anne Rice"},
            {"62059939","2012","4.15","The Selection","Kiera Cass"},
            {"312362080","1994","4.03","One for the Money","Janet Evanovich"},
            {"1400052173","2010","4.04","The Immortal Life of Henrietta Lacks","Rebecca Skloot"},
            {"99446782","1988","4.14","The Silence of the Lambs","Thomas Harris"},
            {"316010669","2005","3.89","Blink: The Power of Thinking Without Thinking","Malcolm Gladwell"},
            {"038572179","2001","3.88","Atonement","Ian McEwan"},
            {"553213695","1915","3.78","Die Verwandlung","Franz Kafka, Stanley Corngold"},
            {"141382899","2007","4.33","The Titan's Curse","Rick Riordan"},
            {"1554681723","2006","4.19","The Art of Racing in the Rain","Garth Stein"},
            {"739303406","2003","3.98","The Devil in the White City: Murder, Magic, and Madness at the Fair that Changed America","Erik Larson, Tony Goldwyn"},
            {"425263908","2012","4.19","Bared to You","Sylvia Day"},
            {"66238501","1956","4.24","The Chronicles of Narnia","C.S. Lewis, Pauline Baynes"},
            {"1558743669","1995","4.08","A Child Called It: One Child's Courage to Survive","Dave Pelzer"},
            {"752864327","1980","3.98","The Bourne Identity","Robert Ludlum"},
            {"786817879","2001","3.82","Artemis Fowl","Eoin Colfer"},
            {"385738935","2009","3.74","Fallen","Lauren Kate"},
            {"142000655","1952","4.35","East of Eden  ","John Steinbeck"},
            {"307341569","2009","3.92","Dark Places","Gillian Flynn"},
            {"385339089","1993","3.97","The Client","John Grisham"},
            {"312291639","2002","3.4","The Nanny Diaries","Emma McLaughlin, Nicola Kraus"},
            {"451527747","1865","4.06","Alice's Adventures in Wonderland","Lewis Carroll, John Tenniel, Martin Gardner"},
            {"192802631","1817","4.13","Persuasion","Jane Austen, James Kinsley, Deidre Shauna Lynch"},
            {"312370830","2007","4.14","Elle s'appelait Sarah","Tatiana de Rosnay"},
            {"452284694","1982","3.99","The Gunslinger","Stephen King"},
            {"140003468","1985","3.89","El amor en los tiempos del cólera","Gabriel García Márquez, Edith Grossman"},
            {"014131088","1999","4","Speak","Laurie Halse Anderson"},
            {"399159347","2013","3.92","The Husband's Secret ","Liane Moriarty"},
            {"385494785","1997","4.11","Into Thin Air: A Personal Account of the Mt. Everest Disaster","Jon Krakauer"},
            {"1416524304","1974","3.93","Carrie","Stephen King"},
            {"031242227","2002","3.7","Running with Scissors","Augusten Burroughs"},
            {"307346609","2006","4.01","World War Z: An Oral History of the Zombie War","Max Brooks"},
            {"385537859","2013","3.8","Inferno","Dan Brown"},
            {"440227534","1989","4.11","Number the Stars","Lois Lowry"},
            {"446692638","1993","4.08","Along Came a Spider","James Patterson"},
            {"450417395","1987","4.11","Misery","Stephen King"},
            {"307341542","2006","3.92","Sharp Objects","Gillian Flynn"},
            {"439366771","1977","3.98","Bridge to Terabithia","Katherine Paterson"},
            {"312360266","2007","3.79","Marked","P.C. Cast, Kristin Cast"},
            {"743269519","1989","4.05","The 7 Habits of Highly Effective People","Stephen R. Covey"},
            {"743477545","1595","3.94","A Midsummer Night's Dream","William Shakespeare, Barbara A. Mowat, Paul Werstine, Catherine Belsey"},
            {"618711651","2005","3.97","Extremely Loud and Incredibly Close","Jonathan Safran Foer"},
            {"375869026","2012","4.43","Wonder","R.J. Palacio"},
            {"039480001","1957","4.15","The Cat in the Hat","Dr. Seuss"},
            {"312641893","2012","4.15","Cinder","Marissa Meyer"},
            {"316206849","2013","3.83","The Cuckoo's Calling","Robert Galbraith, J.K. Rowling"},
            {"545123267","2009","3.78","Shiver","Maggie Stiefvater"},
            {"452011876","1957","3.68","Atlas Shrugged","Ayn Rand, Leonard Peikoff"},
            {"143038257","2006","3.64","Three Cups of Tea ","Greg Mortenson, David Oliver Relin"},
            {"143034901","2001","4.24","La sombra del viento","Carlos Ruiz Zafón, Lucia Graves"},
            {"385738757","2010","3.93","The Scorch Trials","James Dashner"},
            {"767900383","1996","3.72","Under the Tuscan Sun","Frances Mayes"},
            {"399167064","2014","4.2","Big Little Lies","Liane Moriarty"},
            {"590920685","1997","3.97","Ella Enchanted","Gail Carson Levine"},
            {"743297334","1926","3.83","The Sun Also Rises","Ernest Hemingway"},
            {"61120073","1943","4.24","A Tree Grows In Brooklyn ","Betty  Smith"},
            {"446677388","1995","3.93","Kiss the Girls","James Patterson"},
            {"312577222","2015","4.54","The Nightingale","Kristin Hannah"},
            {"1400078776","2005","3.8","Never Let Me Go","Kazuo Ishiguro"},
            {"786890754","2003","4.01","PS, I Love You","Cecelia Ahern"},
            {"1844080382","1938","4.2","Rebecca","Daphne du Maurier, Sally Beauman"},
            {"156030306","1966","4.07","Flowers for Algernon","Daniel Keyes"},
            {"552995878","1989","3.94","Como agua para chocolate","Laura Esquivel, Thomas  Christensen, Carol Christensen"},
            {"812968069","2005","4.05","Snow Flower and the Secret Fan","Lisa See"},
            {"451205766","1969","4.36","The Godfather","Mario Puzo, Robert Thompson, Peter Bart"},
            {"525476881","2006","3.63","An Abundance of Katherines","John Green"},
            {"553803719","1951","4.13","Foundation","Isaac Asimov"},
            {"62255657","2013","3.99","The Ocean at the End of the Lane","Neil Gaiman"},
            {"60513063","1981","4.34","A Light in the Attic","Shel Silverstein"},
            {"751565350","2016","3.75","Harry Potter and the Cursed Child, Parts One and Two","John Tiffany, Jack Thorne, J.K. Rowling"},
            {"61726834","2011","3.99","Delirium","Lauren Oliver"},
            {"385339704","1992","3.95","The Pelican Brief","John Grisham"},
            {"61139378","2002","4.03","Coraline","Neil Gaiman"},
            {"60853980","1990","4.25","Good Omens: The Nice and Accurate Prophecies of Agnes Nutter, Witch","Terry Pratchett, Neil Gaiman"},
            {"140042598","1955","3.64","On the Road","Jack Kerouac"},
            {"1476729085","2013","4.01","The Rosie Project","Graeme Simsion"},
            {"446579939","2008","4.1","The Lucky One","Nicholas Sparks"},
            {"451191153","1943","3.85","The Fountainhead","Ayn Rand, Leonard Peikoff"},
            {"425172902","1984","4.01","The Hunt for Red October","Tom Clancy"},
            {"038039586","1972","4.05","Watership Down","Richard Adams"},
            {"307886263","2011","3.84","Is Everyone Hanging Out Without Me? (And Other Concerns)","Mindy Kaling"},
            {"375414495","2009","4.28","Cutting for Stone","Abraham Verghese"},
            {"006112527","1951","4.08","The Voyage of the Dawn Treader","C.S. Lewis, Pauline Baynes"},
            {"753453800","1882","3.82","Treasure Island","Robert Louis Stevenson"},
            {"1423140591","2011","4.44","The Son of Neptune ","Rick Riordan"},
            {"1451627289","2011","4.29","11/22/63","Stephen King"},
            {"241003008","1969","4.29","The Very Hungry Caterpillar","Eric Carle"},
            {"140285601","1963","4.18","Cat's Cradle","Kurt Vonnegut Jr."},
            {"451528557","1895","3.87","The Time Machine","H.G. Wells, Greg Bear, Carlo Pagetti"},
            {"849946158","2010","4.01","","Todd Burpo, Lynn Vincent"},
            {"385751060","2006","4.1","The Boy in the Striped Pyjamas","John Boyne"},
            {"1892295490","1899","3.42","Heart of Darkness","Joseph Conrad"},
            {"044654759","2010","4.19","Safe Haven","Nicholas Sparks"},
            {"1582701709","2006","3.62","The Secret","Rhonda Byrne"},
            {"60987561","1998","4.17","I Know This Much Is True ","Wally Lamb"},
            {"1416524347","1983","3.91","Pet Sematary","Stephen King"},
            {"671021001","1992","3.84","She's Come Undone","Wally Lamb"},
            {"756404738","2011","4.57","The Wise Man's Fear","Patrick Rothfuss"},
            {"440241901","2003","3.83","Can You Keep a Secret?","Sophie Kinsella"},
            {"1442403543","2011","4.16","City of Fallen Angels","Cassandra Clare"},
            {"743418174","2001","3.7","Good in Bed","Jennifer Weiner"},
            {"380018179","1977","4.22","The Thorn Birds","Colleen McCullough"},
            {"60530928","2008","4.12","The Graveyard Book","Neil Gaiman, Dave McKean"},
            {"1451681739","2012","4","The Light Between Oceans","M.L. Stedman"},
            {"439709105","2003","3.86","Tintenherz","Cornelia Funke, Anthea Bell"},
            {"91883768","1998","3.74","Who Moved My Cheese?","Spencer Johnson, Kenneth H. Blanchard"},
            {"307279464","1997","4.05","A Walk in the Woods","Bill Bryson"},
            {"553279378","1969","4.19","I Know Why the Caged Bird Sings","Maya Angelou"},
            {"61950726","2013","4.14","Orphan Train","Christina Baker Kline"},
            {"1442416866","2012","4.3","City of Lost Souls","Cassandra Clare"},
            {"316204277","2012","3.9","Where'd You Go, Bernadette","Maria Semple"},
            {"375806814","1961","4.04","Where the Red Fern Grows","Wilson Rawls"},
            {"60557818","1996","4.18","Neverwhere","Neil Gaiman"},
            {"571224385","1984","4.08","Nesnesitelná lehkost bytí","Milan Kundera, Michael Henry Heim"},
            {"552135399","1989","4.22","A Prayer for Owen Meany","John Irving"},
            {"316182540","1999","3.93","White Oleander","Janet Fitch"},
            {"039925675","2011","4.19","Legend","Marie Lu"},
            {"743496728","2007","4.1","Nineteen Minutes","Jodi Picoult"},
            {"1401323251","2008","4.25","The Last Lecture","Randy Pausch, Jeffrey Zaslow"},
            {"812511816","1990","4.18","The Eye of the World","Robert Jordan"},
            {"61150142","1998","4","The Pact","Jodi Picoult"},
            {"60764902","1953","4.01","The magician's nephew","C.S. Lewis"},
            {"595440096","2007","4.3","Still Alice","Lisa Genova"},
            {"425263916","2012","4.33","Reflected in You","Sylvia Day"},
            {"375814248","1961","3.99","James and the Giant Peach","Roald Dahl, Quentin Blake"},
            {"446696617","2001","4.05","1st To Die","James Patterson"},
            {"345453743","1996","4.37","The Ultimate Hitchhiker's Guide: Five Complete Novels and One Story","Douglas Adams"},
            {"340896965","2009","3.77","One Day","David Nicholls"},
            {"61969559","2010","3.94","I Am Number Four","Pittacus Lore"},
            {"140275363","-750","3.83","Ἰλιάς","Homer, Robert Fagles, Frédéric Mugler, Bernard Knox"},
            {"316228532","2012","3.28","The Casual Vacancy","J.K. Rowling"},
            {"385339690","1996","3.96","The Runaway Jury","John Grisham"},
            {"316777730","1997","4.08","Naked","David Sedaris"},
            {"375840400","2005","3.96","Eldest","Christopher Paolini"},
            {"140621679","1900","3.98","The Wonderful Wizard of Oz","L. Frank Baum, W.W. Denslow"},
            {"000720230","1951","3.96","Prince Caspian: The Return to Narnia","C.S. Lewis"},
            {"450031063","1975","3.99","Salem's Lot","Stephen King"},
            {"679785892","1971","4.08","Fear and Loathing in Las Vegas: A Savage Journey to the Heart of the American Dream","Hunter S. Thompson, Ralph Steadman"},
            {"1416975888","2011","4.46","Clockwork Prince","Cassandra Clare"},
            {"62268341","2014","3.81","Yes Please","Amy Poehler"},
            {"743477553","1603","3.88","The Tragedy of Othello, The Moor of Venice","William Shakespeare"},
            {"1400033411","1987","3.77","Beloved","Toni Morrison"},
            {"015206396","2008","4.1","Graceling","Kristin Cashore"},
            {"439206472","1999","3.89","The Bad Beginning","Lemony Snicket, Brett Helquist"},
            {"449213943","1929","3.92","Im Westen nichts Neues","Erich Maria Remarque, A.W. Wheen"},
            {"679805273","1990","4.34","Oh, the Places You'll Go!","Dr. Seuss"},
            {"159463176","2012","4.03","And The Mountains Echoed","Khaled Hosseini"},
            {"345404475","1968","4.08","Do Androids Dream of Electric Sheep?","Philip K. Dick, Roger Zelazny"},
            {"141439742","1838","3.85","Oliver Twist","Charles Dickens, George Cruikshank, Philip Horne"},
            {"60652896","1942","4.21","A Grief Observed","C.S. Lewis"},
            {"525423273","2010","4.08","Anna and the French Kiss","Stephanie Perkins"},
            {"7173040","1957","4.36","How the Grinch Stole Christmas!","Dr. Seuss"},
            {"1401207928","1990","4.25","V for Vendetta","Alan Moore, David   Lloyd"},
            {"743223136","2001","4.05","John Adams","David McCullough"},
            {"553384287","2003","3.94","Odd Thomas","Dean Koontz"},
            {"679879250","1997","4.1","The Subtle Knife","Philip Pullman"},
            {"439488400","2000","3.74","Stargirl","Jerry Spinelli"},
            {"1423113381","2010","4.06","The Red Pyramid","Rick Riordan"},
            {"441788386","1961","3.91","Stranger in a Strange Land","Robert A. Heinlein"},
            {"965904830","2004","4.08","Dress Your Family in Corduroy and Denim","David Sedaris"},
            {"141311371","1982","4.22","The BFG","Roald Dahl, Quentin Blake"},
            {"076790818","2003","4.19","A Short History of Nearly Everything","Bill Bryson"},
            {"439227143","1903","3.83","The Call of the Wild","Jack London"},
            {"385738773","2011","3.77","The Death Cure","James Dashner"},
            {"61142026","1999","4.07","Stardust","Neil Gaiman"},
            {"618485228","2003","3.96","The Namesake","Jhumpa Lahiri"},
            {"670022411","2011","3.99","A Discovery of Witches","Deborah Harkness"},
            {"375704027","1987","4.02","ノルウェイの森 [Noruwei no Mori]","Haruki Murakami, Jay Rubin"},
            {"446672211","1995","4","Where the Heart Is","Billie Letts"},
            {"525421580","2010","3.84","Will Grayson, Will Grayson","John Green, David Levithan"},
            {"307276902","2003","3.62","A Million Little Pieces","James Frey"},
            {"1595141758","2008","4.3","Frostbite","Richelle Mead"},
            {"307352145","2012","4.04","Quiet: The Power of Introverts in a World that Can't Stop Talking","Susan Cain"},
            {"440439884","1960","3.8","Island of the Blue Dolphins","Scott O'Dell"},
            {"142437336","1953","3.55","The Crucible","Arthur Miller, Christopher Bigsby"},
            {"689840926","1986","3.68","Hatchet","Gary Paulsen"},
            {"076531178","2006","4.43","Mistborn : The Final Empire","Brandon Sanderson"},
            {"451528956","1886","3.79","The Strange Case of Dr Jekyll and Mr Hyde","Robert Louis Stevenson, Vladimir Nabokov, Mervyn Peake, Dan Chaon"},
            {"679889108","1971","4.35","The Lorax","Dr. Seuss"},
            {"810993139","2004","3.96","Greg Heffley's Journal","Jeff Kinney"},
            {"1599906953","2012","4.24","Throne of Glass","Sarah J. Maas"},
            {"1595141979","2008","4.37","Shadow Kiss","Richelle Mead"},
            {"684803356","1940","3.95","For Whom the Bell Tolls","Ernest Hemingway"},
            {"345505336","2009","3.98","Hotel on the Corner of Bitter and Sweet","Jamie Ford"},
            {"140120831","1985","4","Das Parfum. Die Geschichte eines Mörders","Patrick Süskind, John E. Woods"},
            {"60838582","2001","3.73","Fast Food Nation : The Dark Side of the All-American Meal ","Eric Schlosser"},
            {"747599874","2007","4.06","The Tales of Beedle the Bard","J.K. Rowling"},
            {"441569595","1984","3.88","Neuromancer","William Gibson"},
            {"99910101","1929","3.79","A Farewell to Arms","Ernest Hemingway"},
            {"553212281","1843","4.15","The Tell-Tale Heart","Edgar Allan Poe"},
            {"1590302257","-500","3.95","孫子兵法 [Sūnzi bīngfǎ]","Sun Tzu, Thomas Cleary"},
            {"385344228","2012","3.97","Defending Jacob","William Landay"},
            {"385334206","1973","4.08","Breakfast of Champions","Kurt Vonnegut Jr."},
            {"874774241","1979","3.84","Drawing on the Right Side of the Brain","Betty Edwards"},
            {"60838728","2001","3.92","Bel Canto","Ann Patchett"},
            {"739467352","1997","4","Guns, Germs, and Steel: The Fates of Human Societies","Jared Diamond"},
            {"375508414","1987","4.26","Fried Green Tomatoes at the Whistle Stop Cafe","Fannie Flagg"},
            {"385474547","1958","3.61","Things Fall Apart","Chinua Achebe"},
            {"385338694","2005","3.82","The Undomestic Goddess","Sophie Kinsella"},
            {"1881273156","1990","4.23","The Five Love Languages: How to Express Heartfelt Commitment to Your Mate","Gary Chapman"},
            {"1416589643","2008","3.7","The Other Hand","Chris Cleave"},
            {"031253275","2009","3.59","Evermore","Alyson Noel"},
            {"590032496","1983","4.17","The Witches","Roald Dahl, Quentin Blake"},
            {"743298020","2006","3.95","The Thirteenth Tale","Diane Setterfield"},
            {"1595142509","2010","4.37","Spirit Bound","Richelle Mead"},
            {"1595141987","2009","4.35","Blood Promise","Richelle Mead"},
            {"446676071","1998","3.95","Message in a Bottle","Nicholas Sparks"},
            {"345521307","2011","3.79","The Paris Wife","Paula McLain"},
            {"545044251","1998","4.74","Complete Harry Potter Boxed Set","J.K. Rowling"},
            {"62059963","2013","4.02","The Elite","Kiera Cass"},
            {"156001314","1980","4.11","Il nome della rosa","Umberto Eco, William Weaver, Seán Barrett"},
            {"1416914633","1971","3.77","Go Ask Alice","Beatrice Sparks, Anonymous"},
            {"802130208","1980","3.89","A Confederacy of Dunces","John Kennedy Toole, Walker Percy"},
            {"158049580","1895","4.17","The Importance of Being Earnest","Oscar Wilde"},
            {"1423140605","2012","4.47","The Mark of Athena","Rick Riordan"},
            {"60855924","1983","3.97","The Colour of Magic","Terry Pratchett"},
            {"1400079276","2002","4.13","海辺のカフカ [Umibe no Kafuka]","Haruki Murakami, Philip Gabriel"},
            {"525945563","1981","4.01","Red Dragon","Thomas Harris"},
            {"553803700","1950","4.17","I, Robot","Isaac Asimov"},
            {"451216954","2005","4.21","Dark Lover","J.R. Ward"},
            {"1416989439","2010","4.07","Crescendo","Becca Fitzpatrick"},
            {"61726818","2010","3.92","Before I Fall","Lauren Oliver"},
            {"679457313","1997","3.91","The God of Small Things","Arundhati Roy"},
            {"670024783","2014","4.23","The Invention of Wings","Sue Monk Kidd"},
            {"141043768","2009","4.05","What Alice Forgot","Liane Moriarty"},
            {"553380168","1987","4.12","A Brief History of Time: From the Big Bang to Black Holes","Stephen Hawking, Cao Chi, Phạm Văn Thiều"},
            {"525951652","2010","4.26","Fall of Giants","Ken Follett"},
            {"1439148503","2009","3.89","Under the Dome","Stephen King"},
            {"553380958","1992","4.02","Snow Crash","Neal Stephenson"},
            {"670061050","2006","4.06","Just Listen","Sarah Dessen"},
            {"525467564","1926","4.34","Winnie-the-Pooh","A.A. Milne, Ernest H. Shepard"},
            {"62060554","2011","3.87","Before I Go to Sleep","S.J. Watson"},
            {"1420925539","1887","4.15","A Study in Scarlet","Arthur Conan Doyle"},
            {"375826726","2008","4.03","Brisingr","Christopher Paolini"},
            {"310276993","2002","3.9","The Purpose Driven Life: What on Earth am I Here For?","Rick Warren"},
            {"312360282","2007","3.93","Betrayed: a House of Night Novel","P.C. Cast, Kristin Cast"},
            {"451457811","2000","4.02","Storm Front","Jim Butcher"},
            {"1593082649","1817","3.8","Northanger Abbey","Jane Austen, Alfred MacAdam"},
            {"399162410","2013","4.1","The 5th Wave","Rick Yancey"},
            {"802142842","1997","3.83","Cold Mountain","Charles Frazier"},
            {"60245867","1985","4.24","If You Give a Mouse a Cookie","Laura Joffe Numeroff, Felicia Bond"},
            {"312323867","2005","3.92","Something Blue","Emily Giffin"},
            {"822210894","1947","3.97","A Streetcar Named Desire","Tennessee Williams"},
            {"751537284","2005","3.77","The Historian","Elizabeth Kostova"},
            {"385353308","2014","4.02","Station Eleven","Emily St. John Mandel"},
            {"1476738017","2012","4.35","En man som heter Ove","Fredrik Backman, Henning Koch"},
            {"1406321346","2013","4.59","Clockwork Princess","Cassandra Clare"},
            {"1416500189","1931","3.97","The Good Earth","Pearl S. Buck"},
            {"140135154","1972","3.75","Ways of Seeing","John Berger"},
            {"385335970","1992","4.31","Dragonfly in Amber","Diana Gabaldon"},
            {"743495667","2002","3.78","In Her Shoes","Jennifer Weiner"},
            {"345368584","1989","4.48","The Hobbit","Chuck Dixon, J.R.R. Tolkien, David Wenzel, Sean Deming"},
            {"1594489580","2007","3.89","The Brief Wondrous Life of Oscar Wao","Junot Díaz"},
            {"61120065","1937","3.87","Their Eyes Were Watching God","Zora Neale Hurston"},
            {"439321603","2001","3.95","Fantastic Beasts and Where to Find Them","Newt Scamander, J.K. Rowling, Albus Dumbledore"},
            {"316322407","2012","4.06","I Am Malala: The Girl Who Stood Up for Education and Was Shot by the Taliban","Malala Yousafzai, Christina Lamb"},
            {"141439807","1814","3.84","Mansfield Park","Jane Austen, Kathryn Sutherland, Tony Tanner, Claire Lamont"},
            {"080701429","1946","4.33","…trotzdem Ja zum Leben sagen: Ein Psychologe erlebt das Konzentrationslager","Viktor E. Frankl"},
            {"670038601","2007","3.74","In the Woods","Tana French"},
            {"618680004","2006","3.89","The God Delusion","Richard Dawkins"},
            {"525422943","2011","4.06","Where She Went","Gayle Forman"},
            {"345915593","1978","4.07","The World According to Garp","John Irving"},
            {"515141429","1997","4.04","Killing Floor","Lee Child"},
            {"375757325","1719","3.66","The Life and Strange Surprising Adventures of Robinson Crusoe of York, Mariner","Daniel Defoe, Gerald McCann, Virginia Woolf"},
            {"937832383","1513","3.78","Il Principe","Niccolò Machiavelli, Adolph Caso, Rufus Goodwin, Benjamin Martinez"},
            {"440238153","2000","4.06","The Amber Spyglass","Philip Pullman"},
            {"765346524","1994","4.13","Wizard's First Rule","Terry Goodkind"},
            {"1439153663","2010","4.18","The Kitchen House","Kathleen Grissom"},
            {"316769029","1961","3.98","Franny and Zooey","J.D. Salinger"},
            {"385720920","2001","3.69","Choke","Chuck Palahniuk"},
            {"374528373","1880","4.3","Братья Карамазовы","Fyodor Dostoyevsky, Richard Pevear, Larissa Volokhonsky"},
            {"375822747","2003","3.85","The City of Ember","Jeanne DuPrau"},
            {"60541814","1969","3.87","The Andromeda Strain","Michael Crichton"},
            {"451933028","1996","4.42","The Green Mile","Stephen King"},
            {"000100039","1923","4.22","The Prophet","Kahlil Gibran"},
            {"394541553","1985","4.35","Maus: A Survivor's Tale : My Father Bleeds History","Art Spiegelman"},
            {"312379838","2008","3.95","Untamed: A House of Night Novel","P.C. Cast, Kristin Cast"},
            {"812550757","1986","4.04","Speaker for the Dead","Orson Scott Card"},
            {"684823780","1952","4.31","Mere Christianity","C.S. Lewis"},
            {"1400031702","1992","4.07","The Secret History","Donna Tartt"},
            {"375725784","2000","3.68","A Heartbreaking Work of Staggering Genius","Dave Eggers"},
            {"553381679","1980","4.02","The Clan of the Cave Bear","Jean M. Auel"},
            {"439228905","1877","3.94","Black Beauty","Anna Sewell"},
            {"192833987","1869","4.11","Война и миръ","Leo Tolstoy, Henry Gifford, Aylmer Maude, Louise Maude"},
            {"679735771","1991","3.81","American Psycho","Bret Easton Ellis"},
            {"613371658","2000","3.76","The Princess Diaries","Meg Cabot"},
            {"1400034779","1998","3.75","The No. 1 Ladies' Detective Agency ","Alexander McCall Smith"},
            {"1582406723","2004","4.3","The Walking Dead, Vol. 1: Days Gone Bye","Robert Kirkman, Tony Moore"},
            {"451457994","1968","4.12","2001: A Space Odyssey","Arthur C. Clarke"},
            {"842342702","1995","3.81","Left Behind:  A Novel of the Earth's Last Days","Tim LaHaye, Jerry B. Jenkins"},
            {"62059998","2014","4.21","The One","Kiera Cass"},
            {"545265355","2010","4.49","The Hunger Games Box Set","Suzanne Collins"},
            {"805063897","2001","3.6","Nickel and Dimed: On (Not) Getting By in America","Barbara Ehrenreich"},
    };
}
