function validation() {
    var name = document.getElementById("name").value, err = document.getElementById("err")
    var reg = /^[A-Z-a-z]+$/
    if (!name.match(reg)) {
        err.innerHTML = "plz enter correct name";
        name.focus();
        name.style.border = "2px solid red";
        return false;

    }


}

$(document).on("submit", '#form', function (e) {
    e.preventDefault();
    var x = document.getElementsByName("gender");

    $.ajax({

        type: "POST",
        url: 'addStudent',
        data: {
            name: $('#name').val(),
            id: $('#id').val(),
            GPA: $('#GPA').val(),
            status: $('#status').val(),
            department: $('#department').val(),
            level: $('#level').val(),
            dateOfBirth: $('#dateOfBirth').val(),
            gender: $('#gende').val(),
            mobileNumber: $('#mobileNumber').val(),

            csrfmiddlewaretoken: $('input[name=csrfmiddlewaretoken]').val()
        },
        success: function () {
            alert("new student added succsesfuly!")
        }

    });
}

);
