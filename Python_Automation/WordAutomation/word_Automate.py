from docxtpl import DocxTemplate
doc=DocxTemplate("Resume_One Page for Experienced resume.docx")
context={
    "person_name":"Shane Warne",
    "person_role":"Software Developer",
    "person_address":"Melbourne Cricket Ground",
    "person_no":"+43-299507759",
    "person_mail":"googly@warney.com",
    "person_profile":"Warney.com"
}
doc.render(context)
doc.save("generated_doc.docx")