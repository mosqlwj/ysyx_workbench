// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMain__Syms.h"


VL_ATTR_COLD void VMain___024root__trace_init_sub__TOP__0(VMain___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMain___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+120,"clock", false,-1);
    tracep->declBit(c+121,"reset", false,-1);
    tracep->declBus(c+122,"io_Inst", false,-1, 31,0);
    tracep->pushNamePrefix("Main ");
    tracep->declBit(c+120,"clock", false,-1);
    tracep->declBit(c+121,"reset", false,-1);
    tracep->declBus(c+122,"io_Inst", false,-1, 31,0);
    tracep->declQuad(c+1,"ifu_io_Pc", false,-1, 63,0);
    tracep->declBus(c+3,"ifu_io_Inst", false,-1, 31,0);
    tracep->declBus(c+122,"idu_io_Inst", false,-1, 31,0);
    tracep->declBit(c+4,"idu_io_RegWrite", false,-1);
    tracep->declBit(c+123,"idu_io_MemWrite", false,-1);
    tracep->declBus(c+5,"idu_io_AluOp", false,-1, 4,0);
    tracep->declBus(c+6,"idu_io_AluSrc1Op", false,-1, 4,0);
    tracep->declBus(c+7,"idu_io_AluSrc2Op", false,-1, 4,0);
    tracep->declBus(c+124,"idu_io_PcSrc", false,-1, 4,0);
    tracep->declBus(c+8,"idu_io_RinCtl", false,-1, 3,0);
    tracep->declBus(c+125,"idu_io_MemMask", false,-1, 7,0);
    tracep->declBus(c+126,"idu_io_Rdest", false,-1, 4,0);
    tracep->declBus(c+127,"idu_io_R1", false,-1, 4,0);
    tracep->declBus(c+128,"idu_io_R2", false,-1, 4,0);
    tracep->declQuad(c+9,"idu_io_Imm", false,-1, 63,0);
    tracep->declBit(c+120,"exu_clock", false,-1);
    tracep->declBit(c+121,"exu_reset", false,-1);
    tracep->declBus(c+126,"exu_io_Rdest", false,-1, 4,0);
    tracep->declBus(c+127,"exu_io_R1", false,-1, 4,0);
    tracep->declBus(c+128,"exu_io_R2", false,-1, 4,0);
    tracep->declQuad(c+9,"exu_io_Imm", false,-1, 63,0);
    tracep->declBit(c+4,"exu_io_RegWrite", false,-1);
    tracep->declBit(c+123,"exu_io_MemWrite", false,-1);
    tracep->declBus(c+5,"exu_io_AluOp", false,-1, 4,0);
    tracep->declBus(c+6,"exu_io_AluSrc1Op", false,-1, 4,0);
    tracep->declBus(c+7,"exu_io_AluSrc2Op", false,-1, 4,0);
    tracep->declBus(c+124,"exu_io_PcSrc", false,-1, 4,0);
    tracep->declBus(c+8,"exu_io_RinCtl", false,-1, 3,0);
    tracep->declBus(c+125,"exu_io_MemMask", false,-1, 7,0);
    tracep->declQuad(c+1,"exu_io_PcVal", false,-1, 63,0);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+120,"clock", false,-1);
    tracep->declBit(c+121,"reset", false,-1);
    tracep->declBus(c+126,"io_Rdest", false,-1, 4,0);
    tracep->declBus(c+127,"io_R1", false,-1, 4,0);
    tracep->declBus(c+128,"io_R2", false,-1, 4,0);
    tracep->declQuad(c+9,"io_Imm", false,-1, 63,0);
    tracep->declBit(c+4,"io_RegWrite", false,-1);
    tracep->declBit(c+123,"io_MemWrite", false,-1);
    tracep->declBus(c+5,"io_AluOp", false,-1, 4,0);
    tracep->declBus(c+6,"io_AluSrc1Op", false,-1, 4,0);
    tracep->declBus(c+7,"io_AluSrc2Op", false,-1, 4,0);
    tracep->declBus(c+124,"io_PcSrc", false,-1, 4,0);
    tracep->declBus(c+8,"io_RinCtl", false,-1, 3,0);
    tracep->declBus(c+125,"io_MemMask", false,-1, 7,0);
    tracep->declQuad(c+1,"io_PcVal", false,-1, 63,0);
    tracep->declQuad(c+11,"mem_Raddr", false,-1, 63,0);
    tracep->declQuad(c+13,"mem_Rdata", false,-1, 63,0);
    tracep->declQuad(c+11,"mem_Waddr", false,-1, 63,0);
    tracep->declQuad(c+129,"mem_Wdata", false,-1, 63,0);
    tracep->declBus(c+125,"mem_Wmask", false,-1, 7,0);
    tracep->declBit(c+123,"mem_MemWrite", false,-1);
    tracep->declQuad(c+139,"difftest_gpr_0", false,-1, 63,0);
    tracep->declQuad(c+15,"difftest_gpr_1", false,-1, 63,0);
    tracep->declQuad(c+17,"difftest_gpr_2", false,-1, 63,0);
    tracep->declQuad(c+19,"difftest_gpr_3", false,-1, 63,0);
    tracep->declQuad(c+21,"difftest_gpr_4", false,-1, 63,0);
    tracep->declQuad(c+23,"difftest_gpr_5", false,-1, 63,0);
    tracep->declQuad(c+25,"difftest_gpr_6", false,-1, 63,0);
    tracep->declQuad(c+27,"difftest_gpr_7", false,-1, 63,0);
    tracep->declQuad(c+29,"difftest_gpr_8", false,-1, 63,0);
    tracep->declQuad(c+31,"difftest_gpr_9", false,-1, 63,0);
    tracep->declQuad(c+33,"difftest_gpr_10", false,-1, 63,0);
    tracep->declQuad(c+35,"difftest_gpr_11", false,-1, 63,0);
    tracep->declQuad(c+37,"difftest_gpr_12", false,-1, 63,0);
    tracep->declQuad(c+39,"difftest_gpr_13", false,-1, 63,0);
    tracep->declQuad(c+41,"difftest_gpr_14", false,-1, 63,0);
    tracep->declQuad(c+43,"difftest_gpr_15", false,-1, 63,0);
    tracep->declQuad(c+45,"difftest_gpr_16", false,-1, 63,0);
    tracep->declQuad(c+47,"difftest_gpr_17", false,-1, 63,0);
    tracep->declQuad(c+49,"difftest_gpr_18", false,-1, 63,0);
    tracep->declQuad(c+51,"difftest_gpr_19", false,-1, 63,0);
    tracep->declQuad(c+53,"difftest_gpr_20", false,-1, 63,0);
    tracep->declQuad(c+55,"difftest_gpr_21", false,-1, 63,0);
    tracep->declQuad(c+57,"difftest_gpr_22", false,-1, 63,0);
    tracep->declQuad(c+59,"difftest_gpr_23", false,-1, 63,0);
    tracep->declQuad(c+61,"difftest_gpr_24", false,-1, 63,0);
    tracep->declQuad(c+63,"difftest_gpr_25", false,-1, 63,0);
    tracep->declQuad(c+65,"difftest_gpr_26", false,-1, 63,0);
    tracep->declQuad(c+67,"difftest_gpr_27", false,-1, 63,0);
    tracep->declQuad(c+69,"difftest_gpr_28", false,-1, 63,0);
    tracep->declQuad(c+71,"difftest_gpr_29", false,-1, 63,0);
    tracep->declQuad(c+73,"difftest_gpr_30", false,-1, 63,0);
    tracep->declQuad(c+75,"difftest_gpr_31", false,-1, 63,0);
    tracep->declQuad(c+1,"difftest_PcVal", false,-1, 63,0);
    tracep->declQuad(c+15,"Regs_1", false,-1, 63,0);
    tracep->declQuad(c+17,"Regs_2", false,-1, 63,0);
    tracep->declQuad(c+19,"Regs_3", false,-1, 63,0);
    tracep->declQuad(c+21,"Regs_4", false,-1, 63,0);
    tracep->declQuad(c+23,"Regs_5", false,-1, 63,0);
    tracep->declQuad(c+25,"Regs_6", false,-1, 63,0);
    tracep->declQuad(c+27,"Regs_7", false,-1, 63,0);
    tracep->declQuad(c+29,"Regs_8", false,-1, 63,0);
    tracep->declQuad(c+31,"Regs_9", false,-1, 63,0);
    tracep->declQuad(c+33,"Regs_10", false,-1, 63,0);
    tracep->declQuad(c+35,"Regs_11", false,-1, 63,0);
    tracep->declQuad(c+37,"Regs_12", false,-1, 63,0);
    tracep->declQuad(c+39,"Regs_13", false,-1, 63,0);
    tracep->declQuad(c+41,"Regs_14", false,-1, 63,0);
    tracep->declQuad(c+43,"Regs_15", false,-1, 63,0);
    tracep->declQuad(c+45,"Regs_16", false,-1, 63,0);
    tracep->declQuad(c+47,"Regs_17", false,-1, 63,0);
    tracep->declQuad(c+49,"Regs_18", false,-1, 63,0);
    tracep->declQuad(c+51,"Regs_19", false,-1, 63,0);
    tracep->declQuad(c+53,"Regs_20", false,-1, 63,0);
    tracep->declQuad(c+55,"Regs_21", false,-1, 63,0);
    tracep->declQuad(c+57,"Regs_22", false,-1, 63,0);
    tracep->declQuad(c+59,"Regs_23", false,-1, 63,0);
    tracep->declQuad(c+61,"Regs_24", false,-1, 63,0);
    tracep->declQuad(c+63,"Regs_25", false,-1, 63,0);
    tracep->declQuad(c+65,"Regs_26", false,-1, 63,0);
    tracep->declQuad(c+67,"Regs_27", false,-1, 63,0);
    tracep->declQuad(c+69,"Regs_28", false,-1, 63,0);
    tracep->declQuad(c+71,"Regs_29", false,-1, 63,0);
    tracep->declQuad(c+73,"Regs_30", false,-1, 63,0);
    tracep->declQuad(c+75,"Regs_31", false,-1, 63,0);
    tracep->declQuad(c+1,"pc", false,-1, 63,0);
    tracep->declQuad(c+77,"DataR1", false,-1, 63,0);
    tracep->declQuad(c+79,"DataR2", false,-1, 63,0);
    tracep->declQuad(c+81,"AluSrc1", false,-1, 63,0);
    tracep->declQuad(c+83,"AluSrc2", false,-1, 63,0);
    tracep->declQuad(c+11,"AluOut", false,-1, 63,0);
    tracep->declBus(c+85,"DataIn_lo", false,-1, 7,0);
    tracep->declQuad(c+86,"DataIn_hi", false,-1, 55,0);
    tracep->declQuad(c+13,"MemOut", false,-1, 63,0);
    tracep->declBus(c+88,"DataIn_lo_1", false,-1, 7,0);
    tracep->declQuad(c+89,"DataIn_hi_1", false,-1, 55,0);
    tracep->declBus(c+91,"DataIn_lo_2", false,-1, 15,0);
    tracep->declQuad(c+92,"DataIn_hi_2", false,-1, 47,0);
    tracep->declBus(c+94,"DataIn_lo_3", false,-1, 15,0);
    tracep->declQuad(c+95,"DataIn_hi_3", false,-1, 47,0);
    tracep->declBus(c+97,"DataIn_lo_4", false,-1, 31,0);
    tracep->declBus(c+98,"DataIn_hi_4", false,-1, 31,0);
    tracep->declBus(c+99,"DataIn_lo_5", false,-1, 31,0);
    tracep->declBus(c+100,"DataIn_hi_5", false,-1, 31,0);
    tracep->declQuad(c+101,"pc_hi", false,-1, 42,0);
    tracep->declBus(c+103,"pc_lo", false,-1, 20,0);
    tracep->declQuad(c+104,"pc_hi_1", false,-1, 50,0);
    tracep->declBus(c+106,"pc_lo_1", false,-1, 12,0);
    tracep->pushNamePrefix("difftest ");
    tracep->declQuad(c+139,"gpr_0", false,-1, 63,0);
    tracep->declQuad(c+15,"gpr_1", false,-1, 63,0);
    tracep->declQuad(c+17,"gpr_2", false,-1, 63,0);
    tracep->declQuad(c+19,"gpr_3", false,-1, 63,0);
    tracep->declQuad(c+21,"gpr_4", false,-1, 63,0);
    tracep->declQuad(c+23,"gpr_5", false,-1, 63,0);
    tracep->declQuad(c+25,"gpr_6", false,-1, 63,0);
    tracep->declQuad(c+27,"gpr_7", false,-1, 63,0);
    tracep->declQuad(c+29,"gpr_8", false,-1, 63,0);
    tracep->declQuad(c+31,"gpr_9", false,-1, 63,0);
    tracep->declQuad(c+33,"gpr_10", false,-1, 63,0);
    tracep->declQuad(c+35,"gpr_11", false,-1, 63,0);
    tracep->declQuad(c+37,"gpr_12", false,-1, 63,0);
    tracep->declQuad(c+39,"gpr_13", false,-1, 63,0);
    tracep->declQuad(c+41,"gpr_14", false,-1, 63,0);
    tracep->declQuad(c+43,"gpr_15", false,-1, 63,0);
    tracep->declQuad(c+45,"gpr_16", false,-1, 63,0);
    tracep->declQuad(c+47,"gpr_17", false,-1, 63,0);
    tracep->declQuad(c+49,"gpr_18", false,-1, 63,0);
    tracep->declQuad(c+51,"gpr_19", false,-1, 63,0);
    tracep->declQuad(c+53,"gpr_20", false,-1, 63,0);
    tracep->declQuad(c+55,"gpr_21", false,-1, 63,0);
    tracep->declQuad(c+57,"gpr_22", false,-1, 63,0);
    tracep->declQuad(c+59,"gpr_23", false,-1, 63,0);
    tracep->declQuad(c+61,"gpr_24", false,-1, 63,0);
    tracep->declQuad(c+63,"gpr_25", false,-1, 63,0);
    tracep->declQuad(c+65,"gpr_26", false,-1, 63,0);
    tracep->declQuad(c+67,"gpr_27", false,-1, 63,0);
    tracep->declQuad(c+69,"gpr_28", false,-1, 63,0);
    tracep->declQuad(c+71,"gpr_29", false,-1, 63,0);
    tracep->declQuad(c+73,"gpr_30", false,-1, 63,0);
    tracep->declQuad(c+75,"gpr_31", false,-1, 63,0);
    tracep->declQuad(c+1,"PcVal", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declQuad(c+11,"Raddr", false,-1, 63,0);
    tracep->declQuad(c+11,"Waddr", false,-1, 63,0);
    tracep->declQuad(c+129,"Wdata", false,-1, 63,0);
    tracep->declBus(c+125,"Wmask", false,-1, 7,0);
    tracep->declBit(c+123,"MemWrite", false,-1);
    tracep->declQuad(c+13,"Rdata", false,-1, 63,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+122,"io_Inst", false,-1, 31,0);
    tracep->declBit(c+4,"io_RegWrite", false,-1);
    tracep->declBit(c+123,"io_MemWrite", false,-1);
    tracep->declBus(c+5,"io_AluOp", false,-1, 4,0);
    tracep->declBus(c+6,"io_AluSrc1Op", false,-1, 4,0);
    tracep->declBus(c+7,"io_AluSrc2Op", false,-1, 4,0);
    tracep->declBus(c+124,"io_PcSrc", false,-1, 4,0);
    tracep->declBus(c+8,"io_RinCtl", false,-1, 3,0);
    tracep->declBus(c+125,"io_MemMask", false,-1, 7,0);
    tracep->declBus(c+126,"io_Rdest", false,-1, 4,0);
    tracep->declBus(c+127,"io_R1", false,-1, 4,0);
    tracep->declBus(c+128,"io_R2", false,-1, 4,0);
    tracep->declQuad(c+9,"io_Imm", false,-1, 63,0);
    tracep->declBit(c+131,"ebreak_ebreak_in", false,-1);
    tracep->declBus(c+132,"opcode", false,-1, 6,0);
    tracep->declBus(c+133,"io_Imm_lo", false,-1, 31,0);
    tracep->declBus(c+134,"io_Imm_hi", false,-1, 31,0);
    tracep->declBus(c+135,"io_Imm_lo_1", false,-1, 11,0);
    tracep->declQuad(c+136,"io_Imm_hi_1", false,-1, 51,0);
    tracep->declBus(c+107,"io_Imm_lo_2", false,-1, 11,0);
    tracep->declQuad(c+108,"io_Imm_hi_2", false,-1, 51,0);
    tracep->declBus(c+110,"io_Imm_lo_6", false,-1, 20,0);
    tracep->declQuad(c+111,"io_Imm_hi_6", false,-1, 42,0);
    tracep->declBus(c+113,"io_Imm_lo_8", false,-1, 12,0);
    tracep->declQuad(c+114,"io_Imm_hi_8", false,-1, 50,0);
    tracep->declBus(c+116,"contr_code_2", false,-1, 1,0);
    tracep->declBus(c+117,"contr_code_3", false,-1, 2,0);
    tracep->declBus(c+138,"contr_code_5", false,-1, 1,0);
    tracep->pushNamePrefix("ebreak ");
    tracep->declBit(c+131,"ebreak_in", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu ");
    tracep->declQuad(c+1,"io_Pc", false,-1, 63,0);
    tracep->declBus(c+3,"io_Inst", false,-1, 31,0);
    tracep->declQuad(c+1,"mem_Raddr", false,-1, 63,0);
    tracep->declQuad(c+118,"mem_Rdata", false,-1, 63,0);
    tracep->declQuad(c+139,"mem_Waddr", false,-1, 63,0);
    tracep->declQuad(c+139,"mem_Wdata", false,-1, 63,0);
    tracep->declBus(c+141,"mem_Wmask", false,-1, 7,0);
    tracep->declBit(c+142,"mem_MemWrite", false,-1);
    tracep->pushNamePrefix("mem ");
    tracep->declQuad(c+1,"Raddr", false,-1, 63,0);
    tracep->declQuad(c+139,"Waddr", false,-1, 63,0);
    tracep->declQuad(c+139,"Wdata", false,-1, 63,0);
    tracep->declBus(c+141,"Wmask", false,-1, 7,0);
    tracep->declBit(c+142,"MemWrite", false,-1);
    tracep->declQuad(c+118,"Rdata", false,-1, 63,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VMain___024root__trace_init_top(VMain___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMain___024root__trace_init_top\n"); );
    // Body
    VMain___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VMain___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VMain___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VMain___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VMain___024root__trace_register(VMain___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMain___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VMain___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VMain___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VMain___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VMain___024root__trace_full_sub_0(VMain___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VMain___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMain___024root__trace_full_top_0\n"); );
    // Init
    VMain___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMain___024root*>(voidSelf);
    VMain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VMain___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VMain___024root__trace_full_sub_0(VMain___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMain___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullQData(oldp+1,(vlSelf->Main__DOT__exu__DOT__pc),64);
    tracep->fullIData(oldp+3,((IData)(vlSelf->Main__DOT__ifu__DOT__mem_Rdata)),32);
    tracep->fullBit(oldp+4,(vlSelf->Main__DOT__idu_io_RegWrite));
    tracep->fullCData(oldp+5,(vlSelf->Main__DOT__idu_io_AluOp),5);
    tracep->fullCData(oldp+6,(vlSelf->Main__DOT__idu__DOT__contr_code_2),5);
    tracep->fullCData(oldp+7,(vlSelf->Main__DOT__idu__DOT__contr_code_3),5);
    tracep->fullCData(oldp+8,(vlSelf->Main__DOT__idu_io_RinCtl),4);
    tracep->fullQData(oldp+9,(vlSelf->Main__DOT__idu_io_Imm),64);
    tracep->fullQData(oldp+11,((((QData)((IData)(vlSelf->Main__DOT__exu__DOT___AluOut_T_98[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U])))),64);
    tracep->fullQData(oldp+13,(vlSelf->Main__DOT__exu__DOT__mem_Rdata),64);
    tracep->fullQData(oldp+15,(vlSelf->Main__DOT__exu__DOT__Regs_1),64);
    tracep->fullQData(oldp+17,(vlSelf->Main__DOT__exu__DOT__Regs_2),64);
    tracep->fullQData(oldp+19,(vlSelf->Main__DOT__exu__DOT__Regs_3),64);
    tracep->fullQData(oldp+21,(vlSelf->Main__DOT__exu__DOT__Regs_4),64);
    tracep->fullQData(oldp+23,(vlSelf->Main__DOT__exu__DOT__Regs_5),64);
    tracep->fullQData(oldp+25,(vlSelf->Main__DOT__exu__DOT__Regs_6),64);
    tracep->fullQData(oldp+27,(vlSelf->Main__DOT__exu__DOT__Regs_7),64);
    tracep->fullQData(oldp+29,(vlSelf->Main__DOT__exu__DOT__Regs_8),64);
    tracep->fullQData(oldp+31,(vlSelf->Main__DOT__exu__DOT__Regs_9),64);
    tracep->fullQData(oldp+33,(vlSelf->Main__DOT__exu__DOT__Regs_10),64);
    tracep->fullQData(oldp+35,(vlSelf->Main__DOT__exu__DOT__Regs_11),64);
    tracep->fullQData(oldp+37,(vlSelf->Main__DOT__exu__DOT__Regs_12),64);
    tracep->fullQData(oldp+39,(vlSelf->Main__DOT__exu__DOT__Regs_13),64);
    tracep->fullQData(oldp+41,(vlSelf->Main__DOT__exu__DOT__Regs_14),64);
    tracep->fullQData(oldp+43,(vlSelf->Main__DOT__exu__DOT__Regs_15),64);
    tracep->fullQData(oldp+45,(vlSelf->Main__DOT__exu__DOT__Regs_16),64);
    tracep->fullQData(oldp+47,(vlSelf->Main__DOT__exu__DOT__Regs_17),64);
    tracep->fullQData(oldp+49,(vlSelf->Main__DOT__exu__DOT__Regs_18),64);
    tracep->fullQData(oldp+51,(vlSelf->Main__DOT__exu__DOT__Regs_19),64);
    tracep->fullQData(oldp+53,(vlSelf->Main__DOT__exu__DOT__Regs_20),64);
    tracep->fullQData(oldp+55,(vlSelf->Main__DOT__exu__DOT__Regs_21),64);
    tracep->fullQData(oldp+57,(vlSelf->Main__DOT__exu__DOT__Regs_22),64);
    tracep->fullQData(oldp+59,(vlSelf->Main__DOT__exu__DOT__Regs_23),64);
    tracep->fullQData(oldp+61,(vlSelf->Main__DOT__exu__DOT__Regs_24),64);
    tracep->fullQData(oldp+63,(vlSelf->Main__DOT__exu__DOT__Regs_25),64);
    tracep->fullQData(oldp+65,(vlSelf->Main__DOT__exu__DOT__Regs_26),64);
    tracep->fullQData(oldp+67,(vlSelf->Main__DOT__exu__DOT__Regs_27),64);
    tracep->fullQData(oldp+69,(vlSelf->Main__DOT__exu__DOT__Regs_28),64);
    tracep->fullQData(oldp+71,(vlSelf->Main__DOT__exu__DOT__Regs_29),64);
    tracep->fullQData(oldp+73,(vlSelf->Main__DOT__exu__DOT__Regs_30),64);
    tracep->fullQData(oldp+75,(vlSelf->Main__DOT__exu__DOT__Regs_31),64);
    tracep->fullQData(oldp+77,(vlSelf->Main__DOT__exu__DOT__DataR1),64);
    tracep->fullQData(oldp+79,(vlSelf->Main__DOT__exu__DOT__DataR2),64);
    tracep->fullQData(oldp+81,(vlSelf->Main__DOT__exu__DOT__AluSrc1),64);
    tracep->fullQData(oldp+83,(vlSelf->Main__DOT__exu__DOT__AluSrc2),64);
    tracep->fullCData(oldp+85,((0xffU & vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U])),8);
    tracep->fullQData(oldp+86,(((0x80U & vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U])
                                 ? 0xffffffffffffffULL
                                 : 0ULL)),56);
    tracep->fullCData(oldp+88,((0xffU & (IData)(vlSelf->Main__DOT__exu__DOT__mem_Rdata))),8);
    tracep->fullQData(oldp+89,(((1U & (IData)((vlSelf->Main__DOT__exu__DOT__mem_Rdata 
                                               >> 7U)))
                                 ? 0xffffffffffffffULL
                                 : 0ULL)),56);
    tracep->fullSData(oldp+91,((0xffffU & vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U])),16);
    tracep->fullQData(oldp+92,(((0x8000U & vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U])
                                 ? 0xffffffffffffULL
                                 : 0ULL)),48);
    tracep->fullSData(oldp+94,((0xffffU & (IData)(vlSelf->Main__DOT__exu__DOT__mem_Rdata))),16);
    tracep->fullQData(oldp+95,(((1U & (IData)((vlSelf->Main__DOT__exu__DOT__mem_Rdata 
                                               >> 0xfU)))
                                 ? 0xffffffffffffULL
                                 : 0ULL)),48);
    tracep->fullIData(oldp+97,(vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U]),32);
    tracep->fullIData(oldp+98,(((vlSelf->Main__DOT__exu__DOT___AluOut_T_98[0U] 
                                 >> 0x1fU) ? 0xffffffffU
                                 : 0U)),32);
    tracep->fullIData(oldp+99,((IData)(vlSelf->Main__DOT__exu__DOT__mem_Rdata)),32);
    tracep->fullIData(oldp+100,(((1U & (IData)((vlSelf->Main__DOT__exu__DOT__mem_Rdata 
                                                >> 0x1fU)))
                                  ? 0xffffffffU : 0U)),32);
    tracep->fullQData(oldp+101,(((1U & (IData)((vlSelf->Main__DOT__idu_io_Imm 
                                                >> 0x14U)))
                                  ? 0x7ffffffffffULL
                                  : 0ULL)),43);
    tracep->fullIData(oldp+103,((0x1fffffU & (IData)(vlSelf->Main__DOT__idu_io_Imm))),21);
    tracep->fullQData(oldp+104,(((1U & (IData)((vlSelf->Main__DOT__idu_io_Imm 
                                                >> 0xcU)))
                                  ? 0x7ffffffffffffULL
                                  : 0ULL)),51);
    tracep->fullSData(oldp+106,((0x1fffU & (IData)(vlSelf->Main__DOT__idu_io_Imm))),13);
    tracep->fullSData(oldp+107,(vlSelf->Main__DOT__idu__DOT__io_Imm_lo_2),12);
    tracep->fullQData(oldp+108,(((0x800U & (IData)(vlSelf->Main__DOT__idu__DOT__io_Imm_lo_2))
                                  ? 0xfffffffffffffULL
                                  : 0ULL)),52);
    tracep->fullIData(oldp+110,(vlSelf->Main__DOT__idu__DOT__io_Imm_lo_6),21);
    tracep->fullQData(oldp+111,(((0x100000U & vlSelf->Main__DOT__idu__DOT__io_Imm_lo_6)
                                  ? 0x7ffffffffffULL
                                  : 0ULL)),43);
    tracep->fullSData(oldp+113,(vlSelf->Main__DOT__idu__DOT__io_Imm_lo_8),13);
    tracep->fullQData(oldp+114,(((0x1000U & (IData)(vlSelf->Main__DOT__idu__DOT__io_Imm_lo_8))
                                  ? 0x7ffffffffffffULL
                                  : 0ULL)),51);
    tracep->fullCData(oldp+116,(vlSelf->Main__DOT__idu__DOT__contr_code_2),2);
    tracep->fullCData(oldp+117,(vlSelf->Main__DOT__idu__DOT__contr_code_3),3);
    tracep->fullQData(oldp+118,(vlSelf->Main__DOT__ifu__DOT__mem_Rdata),64);
    tracep->fullBit(oldp+120,(vlSelf->clock));
    tracep->fullBit(oldp+121,(vlSelf->reset));
    tracep->fullIData(oldp+122,(vlSelf->io_Inst),32);
    tracep->fullBit(oldp+123,(((0x17U != (0x7fU & vlSelf->io_Inst)) 
                               & ((0x3003U != (0x707fU 
                                               & vlSelf->io_Inst)) 
                                  & ((0x3023U == (0x707fU 
                                                  & vlSelf->io_Inst)) 
                                     | ((0x13U != (0x707fU 
                                                   & vlSelf->io_Inst)) 
                                        & ((0x33U != 
                                            (0xfe00707fU 
                                             & vlSelf->io_Inst)) 
                                           & ((0x1bU 
                                               != (0x707fU 
                                                   & vlSelf->io_Inst)) 
                                              & ((0x3bU 
                                                  != 
                                                  (0xfe00707fU 
                                                   & vlSelf->io_Inst)) 
                                                 & ((0x1033U 
                                                     != 
                                                     (0xfe00707fU 
                                                      & vlSelf->io_Inst)) 
                                                    & (IData)(vlSelf->Main__DOT__idu__DOT___contr_code_T_218)))))))))));
    tracep->fullCData(oldp+124,(((0x17U == (0x7fU & vlSelf->io_Inst))
                                  ? 0U : ((0x3003U 
                                           == (0x707fU 
                                               & vlSelf->io_Inst))
                                           ? 0U : (
                                                   (0x3023U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->io_Inst))
                                                    ? 0U
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_Inst))
                                                     ? 0U
                                                     : (IData)(vlSelf->Main__DOT__idu__DOT___contr_code_T_446)))))),5);
    tracep->fullCData(oldp+125,(((0x17U == (0x7fU & vlSelf->io_Inst))
                                  ? 0U : ((0x3003U 
                                           == (0x707fU 
                                               & vlSelf->io_Inst))
                                           ? 0U : (
                                                   (0x3023U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->io_Inst))
                                                    ? 0xffU
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_Inst))
                                                     ? 0U
                                                     : 
                                                    ((0x33U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->io_Inst))
                                                      ? 0U
                                                      : 
                                                     ((0x1bU 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_Inst))
                                                       ? 0U
                                                       : 
                                                      ((0x3bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->io_Inst))
                                                        ? 0U
                                                        : 
                                                       ((0x1033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->io_Inst))
                                                         ? 0U
                                                         : 
                                                        ((0x1013U 
                                                          == 
                                                          (0xfc00707fU 
                                                           & vlSelf->io_Inst))
                                                          ? 0U
                                                          : 
                                                         ((0x5033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->io_Inst))
                                                           ? 0U
                                                           : 
                                                          ((0x5013U 
                                                            == 
                                                            (0xfc00707fU 
                                                             & vlSelf->io_Inst))
                                                            ? 0U
                                                            : 
                                                           ((0x40005033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->io_Inst))
                                                             ? 0U
                                                             : 
                                                            ((0x40005013U 
                                                              == 
                                                              (0xfc00707fU 
                                                               & vlSelf->io_Inst))
                                                              ? 0U
                                                              : (IData)(vlSelf->Main__DOT__idu__DOT___contr_code_T_549))))))))))))))),8);
    tracep->fullCData(oldp+126,((0x1fU & (vlSelf->io_Inst 
                                          >> 7U))),5);
    tracep->fullCData(oldp+127,((0x1fU & (vlSelf->io_Inst 
                                          >> 0xfU))),5);
    tracep->fullCData(oldp+128,((0x1fU & (vlSelf->io_Inst 
                                          >> 0x14U))),5);
    tracep->fullQData(oldp+129,(((0x1fU == (0x1fU & 
                                            (vlSelf->io_Inst 
                                             >> 0x14U)))
                                  ? vlSelf->Main__DOT__exu__DOT__Regs_31
                                  : vlSelf->Main__DOT__exu__DOT___GEN_62)),64);
    tracep->fullBit(oldp+131,((0x100073U == vlSelf->io_Inst)));
    tracep->fullCData(oldp+132,((0x7fU & vlSelf->io_Inst)),7);
    tracep->fullIData(oldp+133,((0xfffff000U & vlSelf->io_Inst)),32);
    tracep->fullIData(oldp+134,(((vlSelf->io_Inst >> 0x1fU)
                                  ? 0xffffffffU : 0U)),32);
    tracep->fullSData(oldp+135,((vlSelf->io_Inst >> 0x14U)),12);
    tracep->fullQData(oldp+136,(((vlSelf->io_Inst >> 0x1fU)
                                  ? 0xfffffffffffffULL
                                  : 0ULL)),52);
    tracep->fullCData(oldp+138,(((0x17U == (0x7fU & vlSelf->io_Inst))
                                  ? 0U : ((0x3003U 
                                           == (0x707fU 
                                               & vlSelf->io_Inst))
                                           ? 0U : (
                                                   (0x3023U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->io_Inst))
                                                    ? 0U
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_Inst))
                                                     ? 0U
                                                     : (IData)(vlSelf->Main__DOT__idu__DOT___contr_code_T_446)))))),2);
    tracep->fullQData(oldp+139,(0ULL),64);
    tracep->fullCData(oldp+141,(0U),8);
    tracep->fullBit(oldp+142,(0U));
}
