<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>添加图书信息页面</title>
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
        }
    </style>
</head>


<body>

<h3>添加图书页面</h3>

<form method="post" action="Controller?action=save" onsubmit="return check()">
    <input type="hidden" name="sid" value="${bk.id }">
    <table border="1" width="600">
        <tr>
            <td>ISBN号</td>
            <td><input type="text" name="ISBN" id="1" value="${bk.ISBN }"></td>
            </td>
        </tr>
        <tr>
            <td>书名</td>
            <td><input type="text" name="name" id="2" value="${bk.name}"></td>
        </tr>
        <tr>
            <td>出版社</td>
            <td><input type="text" name="publisher" id="3" value="${bk.publisher }"></td>
        </tr>
        <tr>
            <td>作者</td>
            <td><input type="text" name="author" id="4" value="${bk.author }"></td>
        </tr>

        <tr>
            <td colspan="2"><button type="submit" value="添加" class="btn" >添加 </button></td>
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
