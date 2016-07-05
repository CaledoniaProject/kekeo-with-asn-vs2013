/*************************************************************/
/* Copyright (C) 2016 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED.
 * THIS COPYRIGHT STATEMENT MAY NOT BE REMOVED. */

/* This file was generated by a TRIAL version of the OSS ASN.1 Tools.
 * Applications built using this file can be executed only on the machine
 * on which you run the OSS ASN.1 compiler. */

/* Generated for: 13123 (Trial), License 73090Z. */
/* Abstract syntax: kull_m_kerberos_asn1 */
/* Created: Tue Jul 05 12:55:10 2016 */
/* ASN.1 compiler version: 10.3 */
/* Code generated for runtime version 10.3 or later */
/* Compiler operating system: Windows */
/* Compiler machine type: Intel x86 */
/* Target operating system: Windows */
/* Target machine type: Intel x86 */
/* C compiler options required: -Zp8 (Microsoft) */
/* ASN.1 compiler options and file names specified:
 * -der -root -noSampleCode -messageFormat msvc -allow universaltags
 * C:/Users/Aaron/Desktop/kekeo-master/modules/kull_m_kerberos_asn1.asn
 */

#ifndef OSS_kull_m_kerberos_asn1
#define OSS_kull_m_kerberos_asn1

#include "ossasn1.h"

#define          Ticket_PDU 1
#define          EncTicketPart_PDU 2
#define          AS_REQ_PDU 3
#define          TGS_REQ_PDU 4
#define          AS_REP_PDU 5
#define          TGS_REP_PDU 6
#define          EncASRepPart_PDU 7
#define          EncTGSRepPart_PDU 8
#define          AP_REQ_PDU 9
#define          Authenticator_PDU 10
#define          AP_REP_PDU 11
#define          EncAPRepPart_PDU 12
#define          KRB_SAFE_PDU 13
#define          KRB_PRIV_PDU 14
#define          EncKrbPrivPart_PDU 15
#define          KRB_CRED_PDU 16
#define          EncKrbCredPart_PDU 17
#define          KRB_ERROR_PDU 18
#define          METHOD_DATA_PDU 19
#define          TYPED_DATA_PDU 20
#define          PA_ENC_TIMESTAMP_PDU 21
#define          PA_ENC_TS_ENC_PDU 22
#define          ETYPE_INFO_PDU 23
#define          ETYPE_INFO2_PDU 24
#define          AD_IF_RELEVANT_PDU 25
#define          AD_KDCIssued_PDU 26
#define          AD_AND_OR_PDU 27
#define          AD_MANDATORY_FOR_KDC_PDU 28
#define          KERB_PA_PAC_REQUEST_PDU 29
#define          ChangePasswdData_PDU 30

typedef struct ObjectID {
    unsigned short  length;
    unsigned char   *value;
} ObjectID;

typedef int             Int32;

                    /* signed values representable in 32 bits */
typedef unsigned int    UInt32;

                    /* unsigned 32 bit values */
typedef unsigned int    Microseconds;

                    /* microseconds */
typedef char            *KerberosString;

typedef KerberosString  Realm;

typedef struct _seqof1 {
    struct _seqof1  *next;
    KerberosString  value;
} *_seqof1;

typedef struct PrincipalName {
    Int32           name_type;
    struct _seqof1  *name_string;
} PrincipalName;

typedef GeneralizedTime KerberosTime; /* with no fractional seconds */

typedef struct _octet1 {
    unsigned int    length;
    unsigned char   *value;
} _octet1;

typedef struct HostAddress {
    Int32           addr_type;
    _octet1         address;
} HostAddress;

/* NOTE: HostAddresses is always used as an OPTIONAL field and */
/* should not be empty. */
/* NOTE: subtly different from rfc1510, */
/* but has a value mapping and encodes the same */
typedef struct HostAddresses {
    struct HostAddresses *next;
    HostAddress     value;
} *HostAddresses;

/* NOTE: AuthorizationData is always used as an OPTIONAL field and */
/* should not be empty. */
typedef struct AuthorizationData {
    struct AuthorizationData *next;
    struct {
        Int32           ad_type;
        _octet1         ad_data;
    } value;
} *AuthorizationData;

typedef struct PA_DATA {
        /* NOTE: first tag is [1], not [0] */
    Int32           padata_type;
    _octet1         padata_value; /* might be encoded AP-REQ */
} PA_DATA;

typedef struct KerberosFlags {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} KerberosFlags;

                    /* minimum number of bits shall be sent, */
                    /* but no fewer than 32 */
typedef struct EncryptedData {
    unsigned char   bit_mask;
#       define      kvno_present 0x80
    Int32           etype; /* EncryptionType */
    UInt32          kvno;  /* optional; set in bit_mask kvno_present if
                            * present */
    _octet1         cipher; /* ciphertext */
} EncryptedData;

typedef struct EncryptionKey {
    Int32           keytype; /* actually encryption type */
    _octet1         keyvalue;
} EncryptionKey;

typedef struct Checksum {
    Int32           cksumtype;
    _octet1         checksum;
} Checksum;

typedef struct Ticket {
    unsigned short  tkt_vno;
    Realm           realm;
    PrincipalName   sname;
    EncryptedData   enc_part; /* EncTicketPart */
} Ticket;

typedef KerberosFlags   TicketFlags;

/* encoded Transited field */
typedef struct TransitedEncoding {
    Int32           tr_type; /* must be registered */
    _octet1         contents;
} TransitedEncoding;

/* Encrypted part of ticket */
typedef struct EncTicketPart {
    unsigned char   bit_mask;
#       define      EncTicketPart_starttime_present 0x80
#       define      EncTicketPart_renew_till_present 0x40
#       define      EncTicketPart_caddr_present 0x20
#       define      EncTicketPart_authorization_data_present 0x10
    TicketFlags     flags;
    EncryptionKey   key;
    Realm           crealm;
    PrincipalName   cname;
    TransitedEncoding transited;
    KerberosTime    authtime;
    KerberosTime    starttime;  /* optional; set in bit_mask
                                 * EncTicketPart_starttime_present if present */
    KerberosTime    endtime;
    KerberosTime    renew_till;  /* optional; set in bit_mask
                                  * EncTicketPart_renew_till_present if
                                  * present */
    struct HostAddresses *caddr;  /* optional; set in bit_mask
                                   * EncTicketPart_caddr_present if present */
    struct AuthorizationData *authorization_data;  /* optional; set in bit_mask
                                  * EncTicketPart_authorization_data_present if
                                  * present */
} EncTicketPart;

typedef KerberosFlags   KDCOptions;

typedef struct _seqof2 {
    struct _seqof2  *next;
    Int32           value;
} *_seqof2;

typedef struct _seqof3 {
    struct _seqof3  *next;
    Ticket          value;
} *_seqof3;

typedef struct KDC_REQ_BODY {
    unsigned char   bit_mask;
#       define      KDC_REQ_BODY_cname_present 0x80
#       define      KDC_REQ_BODY_sname_present 0x40
#       define      from_present 0x20
#       define      rtime_present 0x10
#       define      addresses_present 0x08
#       define      enc_authorization_data_present 0x04
#       define      additional_tickets_present 0x02
    KDCOptions      kdc_options;
    PrincipalName   cname;  /* optional; set in bit_mask
                             * KDC_REQ_BODY_cname_present if present */
                                    /* Used only in AS-REQ */
    Realm           realm;
                                    /* Server's realm */
                                    /* Also client's in AS-REQ */
    PrincipalName   sname;  /* optional; set in bit_mask
                             * KDC_REQ_BODY_sname_present if present */
    KerberosTime    from;  /* optional; set in bit_mask from_present if
                            * present */
    KerberosTime    till;
    KerberosTime    rtime;  /* optional; set in bit_mask rtime_present if
                             * present */
    UInt32          nonce;
    struct _seqof2  *etype; /* EncryptionType */
                                    /* in preference order */
    struct HostAddresses *addresses;  /* optional; set in bit_mask
                                       * addresses_present if present */
    EncryptedData   enc_authorization_data;  /* optional; set in bit_mask
                                              * enc_authorization_data_present
                                              * if present */
                                    /* AuthorizationData */
    struct _seqof3  *additional_tickets;  /* optional; set in bit_mask
                                           * additional_tickets_present if
                                           * present */
                                        /* NOTE: not empty */
} KDC_REQ_BODY;

typedef struct _seqof4 {
    struct _seqof4  *next;
    PA_DATA         value;
} *_seqof4;

typedef struct KDC_REQ {
    unsigned char   bit_mask;
#       define      KDC_REQ_padata_present 0x80
        /* NOTE: first tag is [1], not [0] */
    unsigned short  pvno;
    unsigned short  msg_type; /* AS */ /* TGS */
    struct _seqof4  *padata;  /* optional; set in bit_mask
                               * KDC_REQ_padata_present if present */
                            /* NOTE: not empty */
    KDC_REQ_BODY    req_body;
} KDC_REQ;

        /* reserved(0), */
        /* forwardable(1), */
        /* forwarded(2), */
        /* proxiable(3), */
        /* proxy(4), */
        /* may-postdate(5), */
        /* postdated(6), */
        /* invalid(7), */
        /* renewable(8), */
        /* initial(9), */
        /* pre-authent(10), */
        /* hw-authent(11), */
/* the following are new since 1510 */
        /* transited-policy-checked(12), */
        /* ok-as-delegate(13) */
typedef KDC_REQ         AS_REQ;

typedef KDC_REQ         TGS_REQ;

typedef struct KDC_REP {
    unsigned char   bit_mask;
#       define      KDC_REP_padata_present 0x80
    unsigned short  pvno;
    unsigned short  msg_type; /* AS */ /* TGS */
    struct _seqof4  *padata;  /* optional; set in bit_mask
                               * KDC_REP_padata_present if present */
                                /* NOTE: not empty */
    Realm           crealm;
    PrincipalName   cname;
    Ticket          ticket;
    EncryptedData   enc_part;
                                /* EncASRepPart or EncTGSRepPart, */
                                /* as appropriate */
} KDC_REP;

        /* reserved(0), */
        /* forwardable(1), */
        /* forwarded(2), */
        /* proxiable(3), */
        /* proxy(4), */
        /* allow-postdate(5), */
        /* postdated(6), */
        /* unused7(7), */
        /* renewable(8), */
        /* unused9(9), */
        /* unused10(10), */
        /* opt-hardware-auth(11), */
        /* unused12(12), */
        /* unused13(13), */
/* 15 is reserved for canonicalize */
        /* unused15(15), */
/* 26 was unused in 1510 */
        /* disable-transited-check(26), */
/**/
        /* renewable-ok(27), */
        /* enc-tkt-in-skey(28), */
        /* renew(30), */
        /* validate(31) */
typedef KDC_REP         AS_REP;

typedef KDC_REP         TGS_REP;

typedef struct EncKDCRepPart {
    unsigned char   bit_mask;
#       define      key_expiration_present 0x80
#       define      EncKDCRepPart_starttime_present 0x40
#       define      EncKDCRepPart_renew_till_present 0x20
#       define      EncKDCRepPart_caddr_present 0x10
#       define      encrypted_pa_data_present 0x08
    EncryptionKey   key;
    struct LastReq  *last_req;
    UInt32          nonce;
    KerberosTime    key_expiration;  /* optional; set in bit_mask
                                      * key_expiration_present if present */
    TicketFlags     flags;
    KerberosTime    authtime;
    KerberosTime    starttime;  /* optional; set in bit_mask
                                 * EncKDCRepPart_starttime_present if present */
    KerberosTime    endtime;
    KerberosTime    renew_till;  /* optional; set in bit_mask
                                  * EncKDCRepPart_renew_till_present if
                                  * present */
    Realm           srealm;
    PrincipalName   sname;
    struct HostAddresses *caddr;  /* optional; set in bit_mask
                                   * EncKDCRepPart_caddr_present if present */
    struct _seqof4  *encrypted_pa_data;  /* optional; set in bit_mask
                                          * encrypted_pa_data_present if
                                          * present */
} EncKDCRepPart;

typedef EncKDCRepPart   EncASRepPart;

typedef EncKDCRepPart   EncTGSRepPart;

typedef struct LastReq {
    struct LastReq  *next;
    struct {
        Int32           lr_type;
        KerberosTime    lr_value;
    } value;
} *LastReq;

typedef KerberosFlags   APOptions;

typedef struct AP_REQ {
    unsigned short  pvno;
    unsigned short  msg_type;
    APOptions       ap_options;
    Ticket          ticket;
    EncryptedData   authenticator; /* Authenticator */
} AP_REQ;

        /* reserved(0), */
        /* use-session-key(1), */
        /* mutual-required(2) */

/* Unencrypted authenticator */
typedef struct Authenticator {
    unsigned char   bit_mask;
#       define      cksum_present 0x80
#       define      Authenticator_subkey_present 0x40
#       define      Authenticator_seq_number_present 0x20
#       define      Authenticator_authorization_data_present 0x10
    unsigned short  authenticator_vno;
    Realm           crealm;
    PrincipalName   cname;
    Checksum        cksum;  /* optional; set in bit_mask cksum_present if
                             * present */
    Microseconds    cusec;
    KerberosTime    ctime;
    EncryptionKey   subkey;  /* optional; set in bit_mask
                              * Authenticator_subkey_present if present */
    UInt32          seq_number;  /* optional; set in bit_mask
                                  * Authenticator_seq_number_present if
                                  * present */
    struct AuthorizationData *authorization_data;  /* optional; set in bit_mask
                                  * Authenticator_authorization_data_present if
                                  * present */
} Authenticator;

typedef struct AP_REP {
    unsigned short  pvno;
    unsigned short  msg_type;
    EncryptedData   enc_part; /* EncAPRepPart */
} AP_REP;

typedef struct EncAPRepPart {
    unsigned char   bit_mask;
#       define      EncAPRepPart_subkey_present 0x80
#       define      EncAPRepPart_seq_number_present 0x40
    KerberosTime    ctime;
    Microseconds    cusec;
    EncryptionKey   subkey;  /* optional; set in bit_mask
                              * EncAPRepPart_subkey_present if present */
    UInt32          seq_number;  /* optional; set in bit_mask
                                  * EncAPRepPart_seq_number_present if
                                  * present */
} EncAPRepPart;

typedef struct KRB_SAFE_BODY {
    unsigned char   bit_mask;
#       define      KRB_SAFE_BODY_timestamp_present 0x80
#       define      KRB_SAFE_BODY_usec_present 0x40
#       define      KRB_SAFE_BODY_seq_number_present 0x20
#       define      KRB_SAFE_BODY_r_address_present 0x10
    _octet1         user_data;
    KerberosTime    timestamp;  /* optional; set in bit_mask
                                 * KRB_SAFE_BODY_timestamp_present if present */
    Microseconds    usec;  /* optional; set in bit_mask
                            * KRB_SAFE_BODY_usec_present if present */
    UInt32          seq_number;  /* optional; set in bit_mask
                                  * KRB_SAFE_BODY_seq_number_present if
                                  * present */
    HostAddress     s_address;
    HostAddress     r_address;  /* optional; set in bit_mask
                                 * KRB_SAFE_BODY_r_address_present if present */
} KRB_SAFE_BODY;

typedef struct KRB_SAFE {
    unsigned short  pvno;
    unsigned short  msg_type;
    KRB_SAFE_BODY   safe_body;
    Checksum        cksum;
} KRB_SAFE;

typedef struct KRB_PRIV {
    unsigned short  pvno;
    unsigned short  msg_type;
                        /* NOTE: there is no [2] tag */
    EncryptedData   enc_part; /* EncKrbPrivPart */
} KRB_PRIV;

typedef struct EncKrbPrivPart {
    unsigned char   bit_mask;
#       define      EncKrbPrivPart_timestamp_present 0x80
#       define      EncKrbPrivPart_usec_present 0x40
#       define      EncKrbPrivPart_seq_number_present 0x20
#       define      EncKrbPrivPart_r_address_present 0x10
    _octet1         user_data;
    KerberosTime    timestamp;  /* optional; set in bit_mask
                                 * EncKrbPrivPart_timestamp_present if
                                 * present */
    Microseconds    usec;  /* optional; set in bit_mask
                            * EncKrbPrivPart_usec_present if present */
    UInt32          seq_number;  /* optional; set in bit_mask
                                  * EncKrbPrivPart_seq_number_present if
                                  * present */
    HostAddress     s_address; /* sender's addr */
    HostAddress     r_address;  /* optional; set in bit_mask
                                 * EncKrbPrivPart_r_address_present if
                                 * present */
                                /* recip's addr */
} EncKrbPrivPart;

typedef struct KRB_CRED {
    unsigned short  pvno;
    unsigned short  msg_type;
    struct _seqof3  *tickets;
    EncryptedData   enc_part; /* EncKrbCredPart */
} KRB_CRED;

typedef struct KrbCredInfo {
    unsigned char   bit_mask;
#       define      pname_present 0x80
#       define      flags_present 0x40
#       define      authtime_present 0x20
#       define      KrbCredInfo_starttime_present 0x10
#       define      endtime_present 0x08
#       define      KrbCredInfo_renew_till_present 0x04
#       define      KrbCredInfo_sname_present 0x02
#       define      KrbCredInfo_caddr_present 0x01
    EncryptionKey   key;
    Realm           prealm;  /* NULL for not present */
    PrincipalName   pname;  /* optional; set in bit_mask pname_present if
                             * present */
    TicketFlags     flags;  /* optional; set in bit_mask flags_present if
                             * present */
    KerberosTime    authtime;  /* optional; set in bit_mask authtime_present if
                                * present */
    KerberosTime    starttime;  /* optional; set in bit_mask
                                 * KrbCredInfo_starttime_present if present */
    KerberosTime    endtime;  /* optional; set in bit_mask endtime_present if
                               * present */
    KerberosTime    renew_till;  /* optional; set in bit_mask
                                  * KrbCredInfo_renew_till_present if present */
    Realm           srealm;  /* NULL for not present */
    PrincipalName   sname;  /* optional; set in bit_mask
                             * KrbCredInfo_sname_present if present */
    struct HostAddresses *caddr;  /* optional; set in bit_mask
                                   * KrbCredInfo_caddr_present if present */
} KrbCredInfo;

typedef struct _seqof5 {
    struct _seqof5  *next;
    KrbCredInfo     value;
} *_seqof5;

typedef struct EncKrbCredPart {
    unsigned char   bit_mask;
#       define      nonce_present 0x80
#       define      EncKrbCredPart_timestamp_present 0x40
#       define      EncKrbCredPart_usec_present 0x20
#       define      s_address_present 0x10
#       define      EncKrbCredPart_r_address_present 0x08
    struct _seqof5  *ticket_info;
    UInt32          nonce;  /* optional; set in bit_mask nonce_present if
                             * present */
    KerberosTime    timestamp;  /* optional; set in bit_mask
                                 * EncKrbCredPart_timestamp_present if
                                 * present */
    Microseconds    usec;  /* optional; set in bit_mask
                            * EncKrbCredPart_usec_present if present */
    HostAddress     s_address;  /* optional; set in bit_mask s_address_present
                                 * if present */
    HostAddress     r_address;  /* optional; set in bit_mask
                                 * EncKrbCredPart_r_address_present if
                                 * present */
} EncKrbCredPart;

typedef struct KRB_ERROR {
    unsigned char   bit_mask;
#       define      ctime_present 0x80
#       define      cusec_present 0x40
#       define      KRB_ERROR_cname_present 0x20
#       define      e_data_present 0x10
    unsigned short  pvno;
    unsigned short  msg_type;
    KerberosTime    ctime;  /* optional; set in bit_mask ctime_present if
                             * present */
    Microseconds    cusec;  /* optional; set in bit_mask cusec_present if
                             * present */
    KerberosTime    stime;
    Microseconds    susec;
    Int32           error_code;
    Realm           crealm;  /* NULL for not present */
    PrincipalName   cname;  /* optional; set in bit_mask KRB_ERROR_cname_present
                             * if present */
    Realm           realm; /* service realm */
    PrincipalName   sname; /* service name */
    KerberosString  e_text;  /* NULL for not present */
    _octet1         e_data;  /* optional; set in bit_mask e_data_present if
                              * present */
} KRB_ERROR;

typedef struct METHOD_DATA {
    struct METHOD_DATA *next;
    PA_DATA         value;
} *METHOD_DATA;

typedef struct TYPED_DATA {
    struct TYPED_DATA *next;
    struct {
        unsigned char   bit_mask;
#           define      data_value_present 0x80
        Int32           data_type;
        _octet1         data_value;  /* optional; set in bit_mask
                                      * data_value_present if present */
    } value;
} *TYPED_DATA;

/* preauth stuff follows */
typedef EncryptedData   PA_ENC_TIMESTAMP; /* PA-ENC-TS-ENC */

typedef struct PA_ENC_TS_ENC {
    unsigned char   bit_mask;
#       define      pausec_present 0x80
    KerberosTime    patimestamp; /* client's time */
    Microseconds    pausec;  /* optional; set in bit_mask pausec_present if
                              * present */
} PA_ENC_TS_ENC;

typedef struct ETYPE_INFO_ENTRY {
    unsigned char   bit_mask;
#       define      salt_present 0x80
    Int32           etype;
    _octet1         salt;  /* optional; set in bit_mask salt_present if
                            * present */
} ETYPE_INFO_ENTRY;

typedef struct ETYPE_INFO {
    struct ETYPE_INFO *next;
    ETYPE_INFO_ENTRY value;
} *ETYPE_INFO;

typedef struct ETYPE_INFO2_ENTRY {
    unsigned char   bit_mask;
#       define      s2kparams_present 0x80
    Int32           etype;
    KerberosString  salt;  /* NULL for not present */
    _octet1         s2kparams;  /* optional; set in bit_mask s2kparams_present
                                 * if present */
} ETYPE_INFO2_ENTRY;

typedef struct ETYPE_INFO2 {
    struct ETYPE_INFO2 *next;
    ETYPE_INFO2_ENTRY value;
} *ETYPE_INFO2;

typedef struct AuthorizationData *AD_IF_RELEVANT;

typedef struct AD_KDCIssued {
    unsigned char   bit_mask;
#       define      i_sname_present 0x80
    Checksum        ad_checksum;
    Realm           i_realm;  /* NULL for not present */
    PrincipalName   i_sname;  /* optional; set in bit_mask i_sname_present if
                               * present */
    struct AuthorizationData *elements;
} AD_KDCIssued;

typedef struct AD_AND_OR {
    Int32           condition_count;
    struct AuthorizationData *elements;
} AD_AND_OR;

typedef struct AuthorizationData *AD_MANDATORY_FOR_KDC;

typedef struct KERB_PA_PAC_REQUEST {
    ossBoolean      include_pac; /* if TRUE, and no pac present, */
                               /* include PAC. */
                               /*-If FALSE, and pac */
                               /* PAC present, remove PAC */
} KERB_PA_PAC_REQUEST;

typedef struct ChangePasswdData {
    unsigned char   bit_mask;
#       define      targname_present 0x80
    _octet1         newpasswd;
    PrincipalName   targname;  /* optional; set in bit_mask targname_present if
                                * present */
    Realm           targrealm;  /* NULL for not present */
} ChangePasswdData;

#ifndef _OSSNOVALUES

/* OID arc for KerberosV5 */
/**/
/* This OID may be used to identify Kerberos protocol messages */
/* encapsulated in other protocols. */
/**/
/* This OID also designates the OID arc for KerberosV5-related OIDs. */
/**/
/* NOTE: RFC 1510 had an incorrect value (5) for "dod" in its OID. */
extern ObjectID id_krb5;

#endif  /* #ifndef _OSSNOVALUES */


extern void * const kull_m_kerberos_asn1;    /* encoder-decoder control table */
#endif /* OSS_kull_m_kerberos_asn1 */
