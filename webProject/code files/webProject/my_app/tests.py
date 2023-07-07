from django.test import SimpleTestCase

# Create your tests here.


class SimpleTest(SimpleTestCase):
    def test_first_Page(self):
        self.assertEqual(self.client.get('/firsthomepage/').status_code, 200)

    def test_login_Page(self):
        self.assertEqual(self.client.get('/loginpage/').status_code, 200)

    def test_search_Page(self):
        self.assertEqual(self.client.get(
            '/searchtoedit student/').status_code, 200)

    def test_home_Page(self):
        self.assertEqual(self.client.get('/homepage/').status_code, 200)

    def test_edit_Page(self):
        self.assertEqual(self.client.get('/editStudent/').status_code, 200)

    def test_department_Page(self):
        self.assertEqual(self.client.get('/department/').status_code, 200)

    def test_allStudent_Page(self):
        self.assertEqual(self.client.get('/allStudent/').status_code, 200)

    def test_addStudent_Page(self):
        self.assertEqual(self.client.get('/addStudent/').status_code, 200)

    def test_activeStudent_Page(self):
        self.assertEqual(self.client.get('/activeStudent/').status_code, 200)
