package cn.cc;

import org.springframework.stereotype.Component;

@Component
public class StuClass {
    private Integer classId;
    private String className;

    public Integer getClassId() {
        return classId;
    }

    public void setClassId(Integer classId) {
        this.classId = classId;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    @Override
    public String toString() {
        return "StuClass{" +
                "classId=" + classId +
                ", className='" + className + '\'' +
                '}';
    }
}
