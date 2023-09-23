
from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('activeStudent', views.activeStudent, name="active"),
    path('addStudent', views.addStudent, name="add"),
    path('allStudent', views.allStudent, name="all"),
    path('department/<student_id>', views.department, name="department"),
    path('edit/<student_id>', views.editStudent, name="edit"),
    path('homepage', views.homepage, name="home"),
    path('searchtoedit student', views.searchTEditStudent, name="search"),
    path('loginpage', views.loginpage, name="login"),
    path('', views.firsthomepage, name="firstHome"),
    path('results', views.searchResults, name="results"),
    path('delete/<student_id>', views.deleteStudent, name="delete"),
    path('view/<int:pk>', views.TaskDeleteView.as_view(), name="deletee"),
]
