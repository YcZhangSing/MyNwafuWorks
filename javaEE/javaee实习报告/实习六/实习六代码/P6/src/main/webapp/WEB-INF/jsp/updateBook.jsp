<%--
  Created by IntelliJ IDEA.
  User: 18109
  Date: 2022/10/13
  Time: 20:03
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>信息修改</title>
  <link href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
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
      border: black solid 0.5px;
      color: black;
    }
  </style>
</head>
<body>


<div class="container">
  <div class="row clearfix">
    <div class="col-md-12 column">
      <div class="page-header" style="text-align: center">
        <h1>
          <small class="colortxt">修改书籍</small>
        </h1>
      </div>
    </div>
  </div>

  <form action="${pageContext.request.contextPath}/book/updateBook" method="post">
    <div class="form-group">
      <label>书籍编号</label>
      <input type="text" class="form-control" name="id" value="${book.id}" readonly>
    </div>
    <div class="form-group">
      <label>书籍名称</label>
      <input type="text" class="form-control" name="bookName" value="${book.bookName}" required>
    </div>
    <div class="form-group">
      <label>书籍作者</label>
      <input type="text" class="form-control" name="author" value="${book.author}" required>
    </div>
    <div class="form-group">
      <label>书籍价格</label>
      <input type="text" class="form-control" name="price" value="${book.price}" required>
    </div>
    <button type="submit" class="btn">确认修改</button>
  </form>

</div>

</body>
</html>
