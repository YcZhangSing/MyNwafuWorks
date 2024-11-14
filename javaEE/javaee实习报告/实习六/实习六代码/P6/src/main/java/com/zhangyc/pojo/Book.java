package com.zhangyc.pojo;

public class Book {
    private int id;
    private String bookName;
    private double price;
    private String author;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getBookName() {
        return bookName;
    }

    public void setBookName(String bookName) {
        this.bookName = bookName;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    @Override
    public String toString() {
        return "Books{" +
                "bookID=" + id +
                ", bookName='" + bookName + '\'' +
                ", price=" + price +
                ", author='" + author + '\'' +
                '}';
    }

    public Book() {

    }

    public Book(int bookID, String bookName, int price, String author) {
        this.id = bookID;
        this.bookName = bookName;
        this.price = price;
        this.author = author;
    }
}
