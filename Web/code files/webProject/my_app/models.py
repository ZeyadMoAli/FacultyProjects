from tkinter.tix import Tree
from unicodedata import name
from django.db import models

# Create your models here.


class student(models.Model):
    id = models.CharField(max_length=10, primary_key=True)
    name = models.CharField(max_length=25)
    GPA = models.DecimalField(max_digits=4, decimal_places=2, null=True)
    gender = models.CharField(max_length=10)
    department = models.CharField(max_length=50)
    dateOfBirth = models.CharField(max_length=20)
    mobileNumber = models.CharField(max_length=11)
    status = models.CharField(max_length=10)
    level = models.IntegerField(default=1)

    def __str__(self):
        return self.id
