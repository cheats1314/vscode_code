function fun(){
    var a = 11.1
    alert(typeof a);
}

function fun2(){
    var a = 10;
    var b = "20";
    var c = a + b;
    console.log(c);
}

var flag = 0;
function fun1(){
    if (flag == 1) {
        document.getElementById("id1").style.backgroundColor="red";
        flag = 0;
    }
    else {
        document.getElementById("id1").style.backgroundColor="green";
        flag = 1;
    }
}

function validateForm() {
        var username = document.getElementById("username").value;
        var password = document.getElementById("password").value;
        if (username === undefined || password === undefined) {
            alert("用户名和密码不能为空！");
            return false; // 阻止表单提交
        }
        // alert("username:" + username);
        alert("表单验证通过！");
        return true; // 允许表单提交
}
