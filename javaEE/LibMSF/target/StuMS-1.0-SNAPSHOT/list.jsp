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
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        .btn {
            text-align: center;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
            color: black;
        }
    </style>

</head>
<body>
<div style="margin: 0 auto">
<form action="SResult.jsp?action=select" method="post">
    <table border="1" width="700">
        <tr >
            <td colspan="8">
                按书名查询:<input type="text" name="name" style="background-color: transparent"/>
            </select>
                <input type="submit" value="查询" class="btn">
                <a href="add.jsp?action=add">添加</a>
            </td>
        </tr>
        <tr align="center">
            <td>唯一序列号</td>
            <td>ISBN</td>
            <td>书名</td>
            <td>出版社</td>
            <td>作者</td>
            <td>管理</td>
        </tr>
        <c:forEach items="${bkList }" var="bk">
            <tr align="center">
                <td>${bk.id }</td>
                <td>${bk.ISBN }</td>
                <td>${bk.name }</td>
                <td>${bk.publisher }</td>
                <td>${bk.author }</td>
                <td><a href="edit.jsp?action=edit&id=${bk.id }">更新</a>   <a  href="list.jsp?id=${bk.id }&action=delete" onclick='return confirm("确认要删除这本书吗？")'>删除</a></td>
            </tr>
        </c:forEach>
    </table>
</form>
</div>

<h2>${pstest}</h2>
</body>
</html>
