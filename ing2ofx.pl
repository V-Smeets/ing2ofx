#!/usr/bin/perl
#
# ing2ofx <csv-file...>
#
# Convert the CSV file from the ING format into an OFX format.

use strict;
use warnings;

use POSIX;
use Text::CSV;
use XML::LibXML;

use constant {
	NO_NAMESPACE  => "",
	OFX_NAMESPACE => "http://ofx.net/types/2003/04",

	FIELD_DATE          => "Datum",
	FIELD_DESCRIPTION   => "Naam / Omschrijving",
	FIELD_ACCOUNT       => "Rekening",
	FIELD_OTHER_ACCOUNT => "Tegenrekening",
	FIELD_CODE          => "Code",
	FIELD_DIRECTION     => "Af Bij",
	FIELD_AMOUNT        => "Bedrag (EUR)",
	FIELD_KIND          => "Mutatiesoort",
	FIELD_MESSAGE       => "Mededelingen",
	FIELD_RESULT_AMOUNT => "Saldo na mutatie",
	FIELD_TAG           => "Tag",
};

sub gmtDateTime {
	return POSIX::strftime("%Y%m%d%H%M%S", gmtime());
}

sub createTextValueElement {
	my $parent = shift;
	my $elementName = shift;
	my $textValue = shift;
	my $dom = $parent->ownerDocument();

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	my $text = $dom->createTextNode($textValue);
	$element->addChild($text);
}

sub createStatus {
	my $parent = shift;
	my $elementName = shift;
	my $code = shift;
	my $severity = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createTextValueElement($element, "CODE", $code);
	createTextValueElement($element, "SEVERITY", $severity);
}

sub createSignonResponse {
	my $parent = shift;
	my $elementName = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createStatus($element, "STATUS", 0, "INFO");
	createTextValueElement($element, "DTSERVER", gmtDateTime());
	createTextValueElement($element, "LANGUAGE", "DUT");
}

sub createSignonResponseMessageSetV1 {
	my $parent = shift;
	my $elementName = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createSignonResponse($element, "SONRS");
}

sub createBankAccount {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createTextValueElement($element, "BANKID", "INGBNL2A");
}

sub createBankTransactionList {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
}

sub createLedgerBalance {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
}

sub createStatementResponse {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createTextValueElement($element, "CURDEF", "EUR");
	createBankAccount($element, "BANKACCTFROM", @csvRecords);
	createBankTransactionList($element, "BANKTRANLIST", @csvRecords);
	createLedgerBalance($element, "LEDGERBAL", @csvRecords);
}

sub createStatementTransactionResponse {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createTextValueElement($element, "TRNUID", "NONE");
	createStatus($element, "STATUS", 0, "INFO");
	createStatementResponse($element, "STMTRS", @csvRecords);
}

sub createBankResponseMessageSetV1 {
	my $parent = shift;
	my $elementName = shift;
	my @csvRecords = shift;

	my $element = $parent->addNewChild(NO_NAMESPACE, $elementName);
	createStatementTransactionResponse($element, "STMTTRNRS", @csvRecords);
}

sub createOFX {
	my $dom = shift;
	my $elementName = shift;
	my @csvRecords = shift;
	my $piName = "OFX";

	my $pi = $dom->createProcessingInstruction($piName);
	$pi->setData(
		OFXHEADER => "200",
		VERSION => "230",
		SECURITY => "NONE",
		OLDFILEUID => "NONE",
		NEWFILEUID => "NONE",
	);
	$dom->appendChild($pi);

	my $element = $dom->createElementNS(OFX_NAMESPACE, $elementName);
	$dom->setDocumentElement($element);

	createSignonResponseMessageSetV1($element, "SIGNONMSGSRSV1");
	createBankResponseMessageSetV1($element, "BANKMSGSRSV1", @csvRecords);
}

sub convertFile {
	my $csvFilename = shift;
	my $ofxFilename = $csvFilename;
	$ofxFilename =~ s/\.csv$//;
	$ofxFilename .= ".ofx";

	print("Converting from $csvFilename\n");

	my $csvRecords = Text::CSV::csv(
		in => $csvFilename,
		sep_char => ';',
		headers => "auto",
	);
	my $dom = XML::LibXML->createDocument("1.0", "UTF-8");
	my $xsd = XML::LibXML::Schema->new(
		location => "xsd/OFX2_Protocol.xsd",
		no_network => 1,
	);

	createOFX($dom, "OFX", @$csvRecords);

	$dom->toFile($ofxFilename, 1);
	$xsd->validate($dom);
}

sub main {
	foreach my $filename (@ARGV) {
		convertFile($filename);
	}
}

main;
