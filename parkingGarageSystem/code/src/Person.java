public abstract class Person {
    private String name;
    private String password;
    private int id;
    private static int personId=0;

    // constructors , setters and getters
    public Person() {
    }

    public Person(String name, String password) {
        this.name = name;
        this.password = password;
        this.id = ++personId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
        
    }
}
