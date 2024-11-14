package cn.cc;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope("prototype")
public class Student {
    private String xh;
    private String uname;
    private Integer age;

    private StuClass stuClass;

    public String getXh() {
        return xh;
    }

    public void setXh(String xh) {
        this.xh = xh;
    }

    public String getUname() {
        return uname;
    }

    public void setUname(String uname) {
        this.uname = uname;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public StuClass getStuClass() {
        return stuClass;
    }
    @Autowired
    public void setStuClass(StuClass stuClass) {
        this.stuClass = stuClass;
    }

    @Override
    public String toString() {
        return "Student{" +
                "xh='" + xh + '\'' +
                ", uname='" + uname + '\'' +
                ", age=" + age +
                ", stuClass=" + stuClass +
                '}';
    }
}
