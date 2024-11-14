<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2022/12/9
  Time: 16:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
   <table width="600" border="1">
       <caption>
           <a href="/book/add">Add</a>
       </caption>
       <c:forEach items="${books}" var="bk">
           <tr>
               <td>${bk.bookName}</td>
               <td>${bk.author}</td>
               <td>${bk.price}</td>
               <td>
                   <a href="/book/edit?id=${bk.id}">edit</a> |
                   <a href="/book/delete?id=${bk.id}">delete</a>
               </td>
           </tr>
       </c:forEach>
   </table>
</body>
</html>
