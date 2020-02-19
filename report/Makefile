CC := pdflatex

.PHONY: all
all:
	$(CC) report.tex
	bibtex report
	$(CC) report.tex
	$(CC) report.tex

.PHONY: clean
clean:
	rm *.blg *.bbl *.log *.aux

