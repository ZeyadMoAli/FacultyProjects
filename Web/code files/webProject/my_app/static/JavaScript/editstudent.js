

$(document).on("submit", '#form', function (e) {
    e.preventDefault();
    var x = document.getElementsByName("gender");

    $.ajax({

        type: "POST",
        url: 'edit/<student_id>',
        data: {
            name: $('#name').val(),
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
});
