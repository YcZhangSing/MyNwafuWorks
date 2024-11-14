<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>更新图书信息页面</title>
    <style>
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        input{
            background-color: transparent;
        }
        .btn {
            text-align: center;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
            color: black;
            display: block;
            margin: auto;
            align: center;

        }
    </style>
</head>


<body>

<h3>更新图书页面</h3>

<form method="post" action="list.jsp?action=save&id=${bk.id}" onsubmit="return check()">
    <input type="hidden" name="sid" value="${bk.id }">
    <table border="1" width="600">
        <tr>
            <td>唯一序列号</td>
            <td><input type="text" name="id" value="${bk.id }" disabled></td>
        </tr>
        <tr>
            <td>ISBN</td>
            <td><input type="text" id="1" name="ISBN" value="${bk.ISBN }"></td>
            </td>
        </tr>
        <tr>
            <td>书名</td>
            <td><input type="text" id="2" name="name" value="${bk.name}"></td>
        </tr>
        <tr>
            <td>出版社</td>
            <td><input type="text" id="3" name="publisher" value="${bk.publisher }"></td>
        </tr>
        <tr>
            <td>作者</td>
            <td><input type="text" id="4" name="author" value="${bk.author }"></td>
        </tr>

        <tr >
            <td colspan="2" style="margin: auto ;align-content: center;align-self: center;align-items: center"><button type="submit" value="更新" class="btn"> 更新</button></td>
        </tr>
    </table>
    <script>
        function check()
        {
            console.log("调用检查函数");
            if(document.getElementById("1").value=="" || document.getElementById("2").value=="" || document.getElementById("3").value=="" || document.getElementById("4").value=="")
            {
                alert("请完整填写书籍信息后再提交！");
                return false;
            }
            else {
                return true;
            }
        }
    </script>
</form>
</body>
</html>
