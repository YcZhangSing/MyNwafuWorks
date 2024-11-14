<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>更新学生信息页面</title>

</head>


<body>

<h3>更新学生页面</h3>

<form method="post" action="Controller?action=save&id=${stu.id}">
    <input type="hidden" name="sid" value="${stu.id }">
    <table border="1" width="600">
        <tr>
            <td>学号</td>
            <td><input type="text" name="id" value="${stu.id }" disabled></td>
        </tr>
        <tr>
            <td>姓名</td>
            <td><input type="text" name="name" value="${stu.name }"></td>
            </td>
        </tr>
        <tr>
            <td>性别</td>
            <td><input type="text" name="sex" value="${stu.sex }"></td>
        </tr>
        <tr>
            <td>班级</td>
            <td><input type="text" name="cls" value="${stu.cls }"></td>
        </tr>

        <tr>
            <td><input type="submit" value="更新"> </td>
        </tr>
    </table>
</form>
</body>
</html>
