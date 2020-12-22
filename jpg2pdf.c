#include <stdio.h>
#include <string.h>
#include "pdfgen.h"

#define MAXPAGES    500

int main(int argc, char *argv[]) {
     struct pdf_info info = {
        .creator = "JPG2PDF",
        .producer = "JPG2PDF",
        .title = "JPG to PDF",
        .author = "Les Farrell",
        .subject = "This PDF was created by JPG2PDF",
        .date = ""
    };
    struct pdf_object *page[MAXPAGES];
    struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);

    // Check for command line parameters.
    if (argc ==1) {
        printf("To use specify the files on the command line or drop the images onto jpg2pdf.exe\n\n");
        printf("Command line example: jpg2pdf file1.jpg file2.jpg ...\n");
        return 1;
    }

    // Add each jpeg file.
    for (int i = 1; i < argc; i++)
    {
        page[i] = pdf_append_page(pdf);
        pdf_add_image_file(pdf, page[i], 0, 0, PDF_A4_WIDTH, PDF_A4_HEIGHT, argv[i]);
    }

    pdf_save(pdf, "./output.pdf");
    pdf_destroy(pdf);

    return 0;
}
