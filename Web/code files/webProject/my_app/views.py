from multiprocessing import context
from operator import contains
from django.template import loader
from django.contrib import messages
from django.http import HttpRequest, HttpResponse, JsonResponse
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login
from django.views import View
from .models import student
from django.contrib.auth.decorators import login_required


# Create your views here.


def is_ajax(request):
    return request.META.get('HTTP_X_REQUESTED_WITH') == 'XMLHttpRequest'


class TaskDeleteView(View):

    def get(self, request, pk):
        if is_ajax(request=request):
            Student = student.objects.get(pk=pk)
            Student.delete()
            return render(request, 'results.html', {"message": "success"})
        return render(request, 'results.html', {"message": "wrong"})


@login_required
def deleteStudent(request, student_id):
    if not request.user.is_superuser:
        return redirect('home')
    s = student.objects.get(pk=student_id)
    s.delete()
    return redirect('search')


@login_required
def department(request, student_id):
    if not request.user.is_superuser:
        return redirect('home')

    department = request.POST.get("department")
    Info = student.objects.get(pk=student_id)
    if Info.level >= "3":
        Info.department = department
        Info.save()
        return render(request, 'department.html', {'student': student.objects.get(pk=student_id), 'Info': Info, 'message': "changed student department succsessfuly!"})

    else:

        return render(request, 'department.html', {'student': student.objects.get(pk=student_id), 'Info': Info, 'message': "You can not complete the change because the level is less than 2"})


@login_required
def searchResults(request):
    if request.method == "POST":
        searched = request.POST['searched']
        students = student.objects.filter(id=searched)
        return render(request, 'results.html', {'searched': searched, 'students': students})
    else:
        return render(request, 'results.html')


@login_required
def activeStudent(request):

    mydata = student.objects.filter(status='Active').values()
    return render(request, 'activeStudent.html', {'students': mydata})

    mydata = student.objects.filter(status='Active').values()
    mydata = student.objects.filter(status='Active').values()
    template = loader.get_template('activeStudent.html')
    context = {
        'student': mydata,
    }
    return HttpResponse(template.render(context, request))


def username_validate(request):
    usernames = request.GET.get('username')
    username = request.POST['username']
    user = authenticate(request, username=username)
    is_taken = user is not None
    data = {'is_taken': is_taken}
    return JsonResponse(data)


def loginpage(request):
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            # Redirect to a success page.
            return redirect('home')

        else:
            messages.success(
                request, ("The username or password you typed is incorrect. Please try again. If you still can't log in, contact your system administrator."))
            return redirect('login')

    return render(request, 'loginpage.html')


def firsthomepage(request):
    return render(request, 'firsthomepage.html')


@login_required
def searchTEditStudent(request):
    return render(request, 'search to edit student.html')


@login_required
def homepage(request):
    return render(request, 'homepage.html')


@login_required
def allStudent(request):
    if not request.user.is_superuser:
        return redirect('home')

    return render(request, 'allStudent.html', {'student': student.objects.all()})


def getallStudent(request):
    students = student.objects.all()
    return JsonResponse({'students': list(students.values())})


@login_required
def addStudent(request):
    if not request.user.is_superuser:
        return redirect('home')
    name = request.POST.get("name")
    id = request.POST.get("id")
    GPA = request.POST.get("GPA")
    gender = request.POST.get("gender")
    department = request.POST.get("department")
    dateOfBirth = request.POST.get("dateOfBirth")
    mobileNumber = request.POST.get("mobileNumber")
    status = request.POST.get("status")
    level = request.POST.get("level")
    studentInfo = student(name=name, id=id, GPA=GPA, gender=gender, department=department,
                          dateOfBirth=dateOfBirth, mobileNumber=mobileNumber, status=status, level=level)
    studentInfo.save()

    return render(request, 'addStudent.html')
    return HttpResponse('addStudent')


@login_required
def editStudent(request, student_id):
    if not request.user.is_superuser:
        return redirect('home')
    searched = student.objects.get(pk=student_id)
    name = request.POST.get("name")
    id = student_id
    GPA = request.POST.get("GPA")
    gender = request.POST.get("gender")
    department = request.POST.get("department")
    dateOfBirth = request.POST.get("dateOfBirth")
    mobileNumber = request.POST.get("mobileNumber")
    status = request.POST.get("status")
    level = request.POST.get("level")

    studentInfo = student(name=name, id=id, GPA=GPA, gender=gender, department=department,
                          dateOfBirth=dateOfBirth, mobileNumber=mobileNumber, status=status, level=level)
    studentInfo.save()
    return render(request, 'editStudent.html', {'searched': searched})


def addStudent_submitted_form(request):
    return render(request, 'addStudent.html')
