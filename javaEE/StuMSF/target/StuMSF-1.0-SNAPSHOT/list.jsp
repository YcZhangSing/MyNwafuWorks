<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>学生列表页面</title>

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
<h1  class="colortxt">学生信息列表</h1>
<div style="margin: 0 auto">
<form action="SResult.jsp?action=select" method="post">
    <table border="1" width="700">

        <tr >
            <td colspan="8">

                按姓名查询:<input type="text" name="name"/>

            </select>
                &nbsp;&nbsp;&nbsp;
                <input type="submit" value="查询">
                &nbsp;&nbsp;&nbsp;
                <a href="add.jsp?action=add">添加学生</a>
            </td>
        </tr>

        <tr align="center">
            <td>学号</td>
            <td>姓名</td>
            <td>性别</td>
            <td>班级</td>
            <td>管理</td>
        </tr>

        <c:forEach items="${stuList }" var="stu">
            <tr align="center">
                <td>${stu.id }</td>
                <td>${stu.name }</td>
                <td>${stu.sex }</td>
                <td>${stu.cls }</td>
                <td><a href="edit.jsp?action=edit&id=${stu.id }">更新</a>   <a href="list.jsp?id=${stu.id }&action=delete">删除</a></td>
            </tr>
        </c:forEach>
    </table>
</form>
</div>
<h2>${pstest}</h2>
</body>
</html>
