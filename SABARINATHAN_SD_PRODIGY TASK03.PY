import json

def load_contacts():
    try:
        with open("contacts.json", "r") as file:
            contacts = json.load(file)
    except FileNotFoundError:
        contacts = []
    return contacts

def save_contacts(contacts):
    with open("contacts.json", "w") as file:
        json.dump(contacts, file, indent=4)

def add_contact():
    name = input("Enter name: ")
    phone = input("Enter phone number: ")
    email = input("Enter email address: ")
    contact = {"name": name, "phone": phone, "email": email}
    contacts.append(contact)
    save_contacts(contacts)
    print("Contact added successfully.")

def view_contacts():
    if not contacts:
        print("No contacts found.")
    else:
        for idx, contact in enumerate(contacts, 1):
            print(f"{idx}. Name: {contact['name']}, Phone: {contact['phone']}, Email: {contact['email']}")

def edit_contact():
    view_contacts()
    choice = int(input("Enter the index of the contact you want to edit: "))
    if 1 <= choice <= len(contacts):
        contact = contacts[choice - 1]
        print(f"Editing contact: {contact['name']}")
        contact["name"] = input("Enter new name: ")
        contact["phone"] = input("Enter new phone number: ")
        contact["email"] = input("Enter new email address: ")
        save_contacts(contacts)
        
