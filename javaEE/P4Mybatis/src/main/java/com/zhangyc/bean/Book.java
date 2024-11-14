package com.zhangyc.bean;

public class Book {
    private int id;
    private String ISBN;
    private String name;
    private String publisher;
    private String author;
    private float price;
    private String pdate;

    public int getId() {
        return id;
    }

    public float getPrice() {
        return price;
    }

    public String getPdate() {
        return pdate;
    }

    public void setPrice(float price) {
        this.price = price;
    }



    public void setId(int id) {
        this.id = id;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", ISBN='" + ISBN + '\'' +
                ", name='" + name + '\'' +
                ", publisher='" + publisher + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                ", pdate='" + pdate + '\'' +
                '}';
    }

    public void setPdate(String pdate) {
        this.pdate = pdate;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }



    public Book() {
    }
}
