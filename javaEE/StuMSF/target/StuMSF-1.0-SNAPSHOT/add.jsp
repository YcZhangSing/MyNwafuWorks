<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>添加学生信息页面</title>
    <style>
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }
        body{
            background: #ffffcc;
        }
    </style>

</head>


<body>

<h1   class="colortxt">添加学生页面</h1>

<form method="post" action="list.jsp?action=save">
    <input type="hidden" name="sid" value="${stu.id }">
    <table border="1" width="600">
        <tr>
            <td  style="text-align: center">姓名</td>
            <td  style="text-align: center"><input type="text" name="name" value="${stu.name }"></td>
            </td>
        </tr>
        <tr>
            <td  style="text-align: center">性别</td>
            <td  style="text-align: center"><input type="text" name="sex" value="${stu.sex }"></td>
        </tr>
        <tr>
            <td  style="text-align: center">班级</td>
            <td  style="text-align: center"><input type="text" name="cls" value="${stu.cls }"></td>
        </tr>

        <tr>
            <td colspan="3" style="text-align: center"><input type="submit" value="添加"> </td>
        </tr>
    </table>
</form>
</body>
</html>
