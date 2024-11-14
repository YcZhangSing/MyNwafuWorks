package entity;

import lombok.Data;

@Data
public class Book {
    private Integer id;
    private String name;
    private String author;
    private Float price;
    public Book(Integer id, String name, String author, Float price) {
        this.id = id;
        this.name = name;
        this.author = author;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                '}';
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setname(String name) {
        this.name = name;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setPrice(Float price) {
        this.price = price;
    }

    public Integer getId() {
        return id;
    }

    public String getname() {
        return name;
    }

    public String getAuthor() {
        return author;
    }

    public Float getPrice() {
        return price;
    }


}
