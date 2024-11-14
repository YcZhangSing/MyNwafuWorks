<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2022/12/9
  Time: 17:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <form action="/book/save" method="post">
        Name: <input name="bookName" value="${book.bookName}"> <br />
        Author:<input name="author" value="${book.author}" > <br/>
        Price: <input name="price" value="${book.price}" > <br />
        <input type="hidden" name="id" value="${book.id}">
        <button type="submit">Save</button>
    </form>
</body>
</html>
