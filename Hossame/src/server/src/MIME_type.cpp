/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MIME_type.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:03:44 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/11/06 18:05:03 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Server.hpp"


void Server::MIME_types_init()
{
	MIME_types[".bmp"] = "image/bmp";
	MIME_types[".css"] = "text/css";
	MIME_types[".html"] = "text/html";
	MIME_types[".js"] = "text/javascript";
	MIME_types[".json"] = "application/json";
	MIME_types[".xml"] = "application/xml";
	MIME_types[".pdf"] = "application/pdf";
	MIME_types[".zip"] = "application/zip";
	MIME_types[".jpeg"] = "image/jpeg";
	MIME_types[".png"] = "image/png";
	MIME_types[".gif"] = "image/gif";
	MIME_types[".svg"] = "image/svg+xml";
	MIME_types[".mp3"] = "audio/mpeg";
	MIME_types[".ogg"] = "audio/ogg";
	MIME_types[".wav"] = "audio/wav";
	MIME_types[".mp4"] = "video/mp4";
	MIME_types[".mpeg"] = "video/mpeg";
	MIME_types[".mov"] = "video/quicktime";
	MIME_types[".ogg"] = "application/ogg";
	MIME_types[".swf"] = "application/x-shockwave-flash";
	MIME_types[".js"] = "application/javascript";
	MIME_types[".js"] = "application/x-javascript";
	MIME_types[".xml"] = "text/xml";
	MIME_types[".x-www-form-urlencoded"] = "application/x-www-form-urlencoded";
	MIME_types[".form-data"] = "multipart/form-data";
	MIME_types[".rss"] = "application/rss+xml";
	MIME_types[".atom"] = "application/atom+xml";
	MIME_types[".rdf"] = "application/rdf+xml";
	MIME_types[".soap"] = "application/soap+xml";
	MIME_types[".mathml"] = "application/mathml+xml";
	MIME_types[".rdf"] = "application/rdf+xml";
	MIME_types[".zip"] = "application/zip";
	MIME_types[".gz"] = "application/gzip";
	MIME_types[".tar"] = "application/x-tar";
	MIME_types[".compressed"] = "application/x-compressed";
	MIME_types[".gzip"] = "application/x-gzip";
	MIME_types[".bzip2"] = "application/x-bzip2";
	MIME_types[".7z"] = "application/x-7z-compressed";
	MIME_types[".rar"] = "application/x-rar-compressed";
	MIME_types[".zip-compressed"] = "application/x-zip-compressed";
	MIME_types[".stuffit"] = "application/x-stuffit";
	MIME_types[".dvi"] = "application/x-dvi";
	MIME_types[".rtf"] = "application/rtf";
	MIME_types[".latex"] = "application/x-latex";
	MIME_types[".postscript"] = "application/postscript";
	MIME_types[".tex"] = "application/x-tex";
	MIME_types[".sh"] = "application/x-sh";
	MIME_types[".bsh"] = "application/x-bsh";
	MIME_types[".csh"] = "application/x-csh";
	MIME_types[".perl"] = "application/x-perl";
	MIME_types[".python"] = "application/x-python";
	MIME_types[".php"] = "application/x-php";
	MIME_types[".java"] = "application/x-java";
	MIME_types[".ruby"] = "application/x-ruby";
	MIME_types[".shellscript"] = "application/x-shellscript";
	MIME_types[".xhtml"] = "application/xhtml+xml";
	MIME_types[".xop"] = "application/xop+xml";
	MIME_types[".soap"] = "application/soap+xml";
	MIME_types[".atom"] = "application/atom+xml";
	MIME_types[".xslt"] = "application/xslt+xml";
	MIME_types[".xspf"] = "application/xspf+xml";
	MIME_types[".xaml"] = "application/xaml+xml";
	MIME_types[".x-silverlight-app"] = "application/x-silverlight-app";
	MIME_types[".cdlink"] = "application/x-cdlink";
	MIME_types[".certificates"] = "application/x-pkcs7-certificates";
	MIME_types[".pkcs7-mime"] = "application/pkcs7-mime";
	MIME_types[".pkcs7-signature"] = "application/pkcs7-signature";
	MIME_types[".pkcs8"] = "application/pkcs8";
	MIME_types[".pkcs10"] = "application/pkcs10";
	MIME_types[".pkcs12"] = "application/x-pkcs12";
	MIME_types[".x509-ca-cert"] = "application/x-x509-ca-cert";
	MIME_types[".x509-user-cert"] = "application/x-x509-user-cert";
	MIME_types[".pkcs7-certreqresp"] = "application/x-pkcs7-certreqresp";
	MIME_types[".s-mime"] = "application/s-mime";
	MIME_types[".pkix-crl"] = "application/pkix-crl";
	MIME_types[".pgp-encrypted"] = "application/pgp-encrypted";
	MIME_types[".pgp-signature"] = "application/pgp-signature";
	MIME_types[".pem-file"] = "application/x-pem-file";
	MIME_types[".x509-ca-cert"] = "application/x-x509-ca-cert";
	MIME_types[".x509-user-cert"] = "application/x-x509-user-cert";
	MIME_types[".x509-email-cert"] = "application/x-x509-email-cert";
	MIME_types[".x509-root-cert"] = "application/x-x509-root-cert";
	MIME_types[".odt"] = "application/vnd.oasis.opendocument.text";
	MIME_types[".odp"] = "application/vnd.oasis.opendocument.presentation";
	MIME_types[".ods"] = "application/vnd.oasis.opendocument.spreadsheet";
	MIME_types[".cab-compressed"] = "application/vnd.ms-cab-compressed";
	MIME_types[".odg"] = "application/vnd.oasis.opendocument.graphics";
	MIME_types[".tika-msoffice"] = "application/x-tika-msoffice";
	MIME_types[".docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
	MIME_types[".dotx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.template";
	MIME_types[".xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
	MIME_types[".xltx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.template";
	MIME_types[".pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
	MIME_types[".potx"] = "application/vnd.openxmlformats-officedocument.presentationml.template";
	MIME_types[".ppsx"] = "application/vnd.openxmlformats-officedocument.presentationml.slideshow";
	MIME_types[".sldx"] = "application/vnd.openxmlformats-officedocument.presentationml.slide";
	MIME_types[".opendocument.graphics"] = "application/vnd.openxmlformats-officedocument.graphics";
	MIME_types[".opendocument.graphics-template"] = "application/vnd.openxmlformats-officedocument.graphics-template";
	MIME_types[".opendocument.graphics-template"] = "application/vnd.openxmlformats-officedocument.graphics-template";
	MIME_types[".opendocument.formula-template"] = "application/vnd.openxmlformats-officedocument.formula-template";
	MIME_types[".opendocument.formula-template"] = "application/vnd.openxmlformats-officedocument.formula-template";
	MIME_types[".opendocument.drawingml.diagram-layout"] = "application/vnd.openxmlformats-officedocument.drawingml.diagram-layout";
	MIME_types[".opendocument.drawingml.diagram"] = "application/vnd.openxmlformats-officedocument.drawingml.diagram";
	MIME_types[".opendocument.drawingml.chart"] = "application/vnd.openxmlformats-officedocument.drawingml.chart";
	MIME_types[".ms-project"] = "application/vnd.ms-project";
	MIME_types[".visio"] = "application/vnd.visio";
	MIME_types[".x-mspublisher"] = "application/x-mspublisher";
	MIME_types[".xpsdocument"] = "application/vnd.ms-xpsdocument";
	MIME_types[".3gpp.pic-bw-large"] = "application/vnd.3gpp.pic-bw-large";
	MIME_types[".3gpp.pic-bw-small"] = "application/vnd.3gpp.pic-bw-small";
	MIME_types[".3gpp.pic-bw-var"] = "application/vnd.3gpp.pic-bw-var";
	MIME_types[".3gpp2.tcap"] = "application/vnd.3gpp2.tcap";
	MIME_types[".icq"] = "application/x-icq";
	MIME_types[".aim"] = "application/x-aim";
	MIME_types[".msn-messenger"] = "application/x-msn-messenger";
	MIME_types[".miranda"] = "application/x-miranda";
	MIME_types[".t-relay"] = "application/t-relay";
	MIME_types[".kopete"] = "application/x-kopete";
	MIME_types[".gaim"] = "application/x-gaim";
	MIME_types[".mbox"] = "application/mbox";
	MIME_types[".vocaltec-media"] = "application/vocaltec-media";
	MIME_types[".vocaltec-media-control"] = "application/vocaltec-media-control";
	MIME_types[".dvi"] = "application/x-dvi";
	MIME_types[".xpinstall"] = "application/x-xpinstall";
	MIME_types[".sdp"] = "application/sdp";
	MIME_types[".cpio"] = "application/x-cpio";
	MIME_types[".tcl"] = "application/x-tcl";
	MIME_types[".tex-tfm"] = "application/x-tex-tfm";
	MIME_types[".texinfo"] = "application/x-texinfo";
	MIME_types[".tei+xml"] = "application/tei+xml";
	MIME_types[".sru+xml"] = "application/sru+xml";
	MIME_types[".font-woff"] = "application/x-font-woff";
	MIME_types[".font-otf"] = "application/x-font-otf";
	MIME_types[".font-ttf"] = "application/x-font-ttf";
	MIME_types[".java-archive"] = "application/java-archive";
	MIME_types[".java-vm"] = "application/java-vm";
	MIME_types[".msdownload"] = "application/x-msdownload";
	MIME_types[".executable"] = "application/x-executable";
	MIME_types[".oda"] = "application/oda";
	MIME_types[".opentype-font"] = "application/x-opentype-font";
	MIME_types[".ms-wmd"] = "application/x-ms-wmd";
	MIME_types[".ms-wmz"] = "application/x-ms-wmz";
	MIME_types[".winhlp"] = "application/winhlp";
	MIME_types[".wais-source"] = "application/x-wais-source";
	MIME_types[".ms-access"] = "application/vnd.ms-access";
	MIME_types[".bcpio"] = "application/x-bcpio";
	MIME_types[".dbf"] = "application/x-dbf";
	MIME_types[".director"] = "application/x-director";
	MIME_types[".freemind"] = "application/x-freemind";
	MIME_types[".msmediaview"] = "application/x-msmediaview";
	MIME_types[".msmoney"] = "application/x-msmoney";
	MIME_types[".pkcs7-certificates"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.template";
	MIME_types[".pkcs7-certificates"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
	MIME_types[".ms-pki.stl"] = "application/vnd.ms-pki.stl";
	MIME_types[".ms-powerpoint"] = "application/vnd.ms-powerpoint";
	MIME_types[".ms-pki.pko"] = "application/vnd.ms-pki.pko";
	MIME_types[".ms-pki.seccat"] = "application/vnd.ms-pki.seccat";
	MIME_types[".quicktimeplayer"] = "application/x-quicktimeplayer";
	MIME_types[".shar"] = "application/x-shar";
	MIME_types[".stuffit"] = "application/x-stuffit";
	MIME_types[".sv4cpio"] = "application/x-sv4cpio";
	MIME_types[".sv4crc"] = "application/x-sv4crc";
	MIME_types[".sun.xml.draw"] = "application/vnd.sun.xml.draw";
	MIME_types[".sun.xml.calc"] = "application/vnd.sun.xml.calc";
	MIME_types[".sun.xml.math"] = "application/vnd.sun.xml.math";
	MIME_types[".sun.xml.impress"] = "application/vnd.sun.xml.impress";
	MIME_types[".sun.xml.writer"] = "application/vnd.sun.xml.writer";
	MIME_types[".sun.xml.writer.global"] = "application/vnd.sun.xml.writer.global";
	MIME_types[".sun.xml.writer.template"] = "application/vnd.sun.xml.writer.template";
}