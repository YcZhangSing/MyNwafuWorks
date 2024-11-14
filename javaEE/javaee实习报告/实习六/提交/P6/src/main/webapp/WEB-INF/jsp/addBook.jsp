<%--
  Created by IntelliJ IDEA.
  User: 18109
  Date: 2022/10/13
  Time: 19:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>新增书籍</title>
  <link href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
</head>
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
<body>

<div class="container">
  <div class="row clearfix">
    <div class="col-md-12 column">
      <div style="text-align: center" class="page-header">
        <h1>
          <small class="colortxt" style="text-align: center">新增书籍</small>
        </h1>
      </div>
    </div>
  </div>

  <form action="${pageContext.request.contextPath}/book/addBook" method="post">
    <div class="form-group">
      <label>书籍名称</label>
      <input type="text" class="form-control" name="bookName" placeholder="书籍名称" required>
    </div>
    <div class="form-group">
      <label>书籍作者</label>
      <input type="text" class="form-control" name="author" placeholder="书籍作者" required>
    </div>
    <div class="form-group">
      <label>书籍价格</label>
      <input type="text" class="form-control" name="price" placeholder="书籍价格" required>
    </div>
    <button type="submit" class="btn">添加</button>
  </form>

</div>

</body>
</html>
