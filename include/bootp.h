/*
 * libtins is a net packet wrapper library for crafting and
 * interpreting sniffed packets.
 *
 * Copyright (C) 2011 Nasel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __BOOTP_H
#define __BOOTP_H

#include <stdint.h>

#include <stdint.h>

#include "pdu.h"


namespace Tins {

    /**
     * \brief Class representing a BootP packet.
     */
    class BootP : public PDU {

    public:
        /**
         * \brief Enum which contains the different opcodes BootP messages.
         */
        enum OpCodes {
            BOOTREQUEST = 1,
            BOOTREPLY = 2   
        };
         
        /** 
         * \brief Creates an instance of BootP.
         * 
         * This sets the size of the vend field to 64, as the BootP RFC
         * states.
         */
        BootP();
        
        /**
         * \brief Constructor which creates a BootP object from a buffer and adds all identifiable
         * PDUs found in the buffer as children of this one.
         * \param buffer The buffer from which this PDU will be constructed.
         * \param total_sz The total size of the buffer.
         * \param vend_field_size The vend field size to allocate. 
         * Subclasses might use 0 to provide their own interpretation of this field.
         */
        BootP(const uint8_t *buffer, uint32_t total_sz, uint32_t vend_field_size = 64);
        
        /** \brief BootP destructor.
         * 
         * This frees the memory allocated to hold the vend field.
         */
        ~BootP();
        
        /* Getters */
        
        /** \brief Getter for the opcode field.
         * \return The opcode field for this BootP PDU.
         */
        uint8_t opcode() const { return _bootp.opcode; }
         
        /** \brief Getter for the htype field.
         * \return The htype field for this BootP PDU.
         */
        uint8_t htype() const { return _bootp.htype; }
          
        /** \brief Getter for the hlen field.
         * \return The hlen field for this BootP PDU.
         */
        uint8_t hlen() const { return _bootp.hlen; }
        
        /** \brief Getter for the hops field.
         * \return The hops field for this BootP PDU.
         */
        uint8_t hops() const { return _bootp.hops; }
        
        /** \brief Getter for the xid field.
         * \return The xid field for this BootP PDU.
         */
        uint32_t xid() const { return _bootp.xid; }
        
        /** \brief Getter for the secs field.
         * \return The secs field for this BootP PDU.
         */
        uint16_t secs() const { return _bootp.secs; }
        
        /** \brief Getter for the padding field.
         * \return The padding field for this BootP PDU.
         */
        uint16_t padding() const { return _bootp.padding; }
        
        /** \brief Getter for the ciaddr field.
         * \return The ciaddr field for this BootP PDU.
         */
        uint32_t ciaddr() const { return _bootp.ciaddr; }
        
        /** \brief Getter for the yiaddr field.
         * \return The yiaddr field for this BootP PDU.
         */
        uint32_t yiaddr() const { return _bootp.yiaddr; }
        
        /** \brief Getter for the siaddr field.
         * \return The siaddr field for this BootP PDU.
         */
        uint32_t siaddr() const { return _bootp.siaddr; }
        
        /** \brief Getter for the giaddr field.
         * \return The giaddr field for this BootP PDU.
         */
        uint32_t giaddr() const { return _bootp.giaddr; }
        
        /** \brief Getter for the chaddr field.
         * \return The chddr field for this BootP PDU.
         */
        const uint8_t *chaddr() const { return _bootp.chaddr; }
         
        /** \brief Getter for the sname field.
         * \return The sname field for this BootP PDU.
         */
        const uint8_t *sname() const { return _bootp.sname; }
        
        /** \brief Getter for the file field.
         * \return The file field for this BootP PDU.
         */
        const uint8_t *file() const { return _bootp.file; }
        
        /** \brief Getter for the vend field.
         * \return The vend field for this BootP PDU.
         */
        uint8_t *vend() { return _vend; }
        
        /** \brief Getter for the vend field.
         */
        uint32_t vend_size() const { return _vend_size; }
        
        /** \brief Getter for the header size.
         * \return Returns the BOOTP header size.
         * \sa PDU::header_size
         */ 
        uint32_t header_size() const;
        /* Setters */
        
        /** \brief Setter for the opcode field.
         * \param new_opcode The opcode to be set.
         */
        void opcode(uint8_t new_opcode);
        
        /** \brief Setter for the htype field.
         * \param new_htype The htype to be set.
         */
        void htype(uint8_t new_htype);
        
        /** \brief Setter for the hlen field.
         * \param new_hlen The hlen to be set.
         */
        void hlen(uint8_t new_hlen);
        
        /** \brief Setter for the hops field.
         * \param new_hops The hops to be set.
         */
        void hops(uint8_t new_hops);
        
        /** \brief Setter for the xid field.
         * \param new_xid The xid to be set.
         */
        void xid(uint32_t new_xid);
        
        /** \brief Setter for the secs field.
         * \param new_secs The secs to be set.
         */
        void secs(uint16_t new_secs);
        
        /** \brief Setter for the padding field.
         * \param new_padding The padding to be set.
         */
        void padding(uint16_t new_padding);
        
        /** \brief Setter for the ciaddr field.
         * \param new_ciaddr The ciaddr to be set.
         */
        void ciaddr(uint32_t new_ciaddr);
        
        /** \brief Setter for the yiaddr field.
         * \param new_yiaddr The yiaddr to be set.
         */
        void yiaddr(uint32_t new_yiaddr);
        
        /** \brief Setter for the siaddr field.
         * \param new_siaddr The siaddr to be set.
         */
        void siaddr(uint32_t new_siaddr);
        
        /** \brief Setter for the giaddr field.
         * \param new_giaddr The giaddr to be set.
         */
        void giaddr(uint32_t new_giaddr);
        
        /** \brief Setter for the chaddr field.
         * \param new_chaddr The chaddr to be set.
         */
        void chaddr(uint8_t *new_chaddr);
        
        /** \brief Setter for the sname field.
         * \param new_sname The sname to be set.
         */
        void sname(uint8_t *new_sname);
        
        /** \brief Setter for the file field.
         * \param new_file The file to be set.
         */
        void file(uint8_t *new_file);
        
        /** \brief Setter for the vend field.
         * \param new_vend The vend to be set.
         * \param size The size of the new vend field.
         */
        void vend(uint8_t *new_vend, uint32_t size);
    protected:
        void write_serialization(uint8_t *buffer, uint32_t total_sz, const PDU *parent);
    private:
        /**
         * Struct that represents the Bootp datagram.
         */
        struct bootphdr {
            uint8_t opcode;
            uint8_t htype;
            uint8_t hlen;
            uint8_t hops;
            uint32_t xid;
            uint16_t secs;
            uint16_t padding;
            uint32_t ciaddr;
            uint32_t yiaddr;
            uint32_t siaddr;
            uint32_t giaddr;
            uint8_t chaddr[16];
            uint8_t sname[64];
            uint8_t file[128];
        } __attribute__((__packed__));
        
        
        bootphdr _bootp;
        uint8_t *_vend;
        uint32_t _vend_size;
    };
};

#endif